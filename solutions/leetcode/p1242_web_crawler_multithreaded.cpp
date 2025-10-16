/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    class WorkQueue {
    private:
        std::queue<string> q_{};
        mutable std::mutex mtx_{};
        std::condition_variable cv_{};
        std::atomic<int> active_tasks_{0};
        bool done_{false};
    
    public:
        WorkQueue() = default;

        void push(const std::string& s) {
            {
                std::scoped_lock lck(mtx_);
                q_.push(s);
            }
            cv_.notify_one();
        }

        bool pop(std::string& res) {
            {
                std::unique_lock<std::mutex> lck(mtx_);
                cv_.wait(lck, [this] {
                    return !q_.empty() || done_;
                });
                if(q_.empty()) return false;

                res = q_.front();
                q_.pop();
                active_tasks_++;
            }
            cv_.notify_one();
            return true;
        }

        void task_done() {
            {
                std::scoped_lock lck(mtx_);
                if(--active_tasks_ == 0 && q_.empty()) {
                    done_ = true;
                }
                cv_.notify_all();
                // notify all that either done
                // or more work has been added to queue
            }
        }
    };

    class VisitedSet {
    private:
        std::unordered_set<string> set_{};
        mutable std::mutex mtx_{};

    public:
        bool try_visit(const std::string& url) {
            std::scoped_lock lck(mtx_);
            return set_.insert(url).second;
        }

        vector<string> get_all() const noexcept {
            std::scoped_lock lck(mtx_);
            return vector<string>(set_.begin(), set_.end());
        }
    };

    std::string get_hostname(const std::string& url) {
        int idx = url.find('/', 7);
        return url.substr(7, idx-7);
    }

    void worker(WorkQueue& wq, VisitedSet& vs, const string host, HtmlParser& hp) {
        std::string url;
        while (wq.pop(url)) {
            for(const std::string& v : hp.getUrls(url)) {
                if(get_hostname(v) == host) {
                    if(vs.try_visit(v)) {
                        wq.push(v);
                    }
                }
            }
            wq.task_done();
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        WorkQueue wq;
        VisitedSet vs;

        wq.push(startUrl);
        vs.try_visit(startUrl);
        const std::string host = get_hostname(startUrl);

        const size_t num_threads = std::min(
            std::thread::hardware_concurrency(),
            8U
        );

        std::vector<std::thread> thread_pool;
        thread_pool.reserve(num_threads);
        for(size_t i=0; i<num_threads; ++i) {
            thread_pool.emplace_back(
                &Solution::worker,
                this,
                std::ref(wq),
                std::ref(vs),
                std::ref(host),
                std::ref(htmlParser)
            );
        }

        for(auto& t : thread_pool) {
            t.join();
        }

        return vs.get_all();
    }
};

// to create thread_pool create a vector of threads that execute a task worker() until completion
// iterate over vector and call t.join() to wait for all threads to finish execution
// every thread should wait for work to appear in the work queue
// use a mutex and a condition variable to properly protect the work queue
// to pass variables to a thread we must use std::ref() because threads take everything by copy or move NOT by reference
// use std::thread::hardware_concurrency() to get number of cores on CPU
// need to use std::unique_lock<std::mutex> with std::condition variable, we CANNOT use std::scoped_lock