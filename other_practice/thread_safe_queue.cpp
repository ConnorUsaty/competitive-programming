/*
Practicing implementation of a thread safe queue utilizing mutex and condition variable
*/

#include <mutex>
#include <condition_variable>
#include <deque>

template <typename T>
class Queue {
private:
    std::deque<T> _q;
    std::mutex _mtx;
    std::condition_variable _cv;

public:
    // have to return item via reference due to threading
    void pop(T& item){
        // have to use unique_lock when using cv, else would use scoped_lock
        std::unique_lock<std::mutex> lock(_mtx);
        if(_q.empty()){
            _cv.wait(lock); // releases mutex lock and waits (sleeps) until notified by conditional variable
        }
        item = _q.back();
        _q.pop_back();
    }

    void push(const T& item){
        // lock for critical section (accessing and modifying shared data _q)
        std::unique_lock<std::mutex> lock(_mtx);
        _q.push_back(item);
        lock.unlock();
        _cv.notify_one(); // notify a waiting thread that they can extract an item from the queue
    }
};
