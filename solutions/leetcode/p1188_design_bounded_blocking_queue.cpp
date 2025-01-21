class BoundedBlockingQueue {
private:
    int _cap;
    queue<int> _q;
    std::mutex _mtx;
    std::condition_variable _cv;

public:
    BoundedBlockingQueue(int capacity) : _cap(capacity) {} ;
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(_mtx);
        while(_q.size()>=_cap){
            _cv.wait(lock); // release mutex until notifed
        }
        _q.push(element);
        lock.unlock();
        _cv.notify_one();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> lock(_mtx);
        while(_q.empty()){
            _cv.wait(lock); // release mutex until notified
        }
        int item = _q.front();
        _q.pop();
        lock.unlock();
        _cv.notify_one();
        return item;
    }
    
    int size() {
        return _q.size();
    }
};

// need to acquire lock before accessing or modifying any share data
// need to sleep threads until notified if they cannot immediately perform the intended function
// need to use std::unique_lock<std::mutex> when using std::condition_variables or need more lock control than just scope
// _cv.wait(lock); need to pass in the lock NOT the mutex
// need to unlock before notifying to ensure thread is not immediately blocked again