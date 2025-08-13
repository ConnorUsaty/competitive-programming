class BoundedBlockingQueue {
private:
    size_t capacity_;
    queue<int> q_{};
    mutex mtx_{};
    condition_variable cv_{};

public:
    BoundedBlockingQueue(int capacity) : capacity_(capacity) {}
    
    void enqueue(int element) {
        unique_lock<mutex> lck(mtx_);
        while(q_.size() == capacity_){
            cv_.wait(lck);
        }

        q_.push(element);
        lck.unlock();
        cv_.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> lck(mtx_);
        while(q_.empty()){
            cv_.wait(lck);
        }
        int element = q_.front();
        q_.pop();
        lck.unlock();
        cv_.notify_one();
        return element;
    }
    
    int size() {
        scoped_lock lck(mtx_);
        return q_.size();
    }
};

// need to acquire lock before accessing or modifying any share data
// need to sleep threads until notified if they cannot immediately perform the intended function
// need to use std::unique_lock<std::mutex> when using std::condition_variables or need more lock control than just scope
// _cv.wait(lock); need to pass in the lock NOT the mutex
// need to unlock before notifying to ensure thread is not immediately blocked again