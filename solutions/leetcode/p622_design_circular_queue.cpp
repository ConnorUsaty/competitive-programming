class MyCircularQueue {
private:
    std::vector<int> q_;
    size_t size_{0};
    size_t front_{0};

public:
    MyCircularQueue(int k) : q_(k) {}
    
    bool enQueue(int value) {
        if(!isFull()) {
            size_t idx = front_ + size_;
            if(idx >= q_.size()) idx -= q_.size();
            q_[idx] = value;
            size_++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            front_++;
            size_--;
            if(front_>=q_.size()) front_ = 0;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty()) {
            return q_[front_];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()) {
            size_t idx = front_ + size_ - 1;
            if(idx >= q_.size()) idx -= q_.size();
            return q_[idx];
        }
        return -1;
    }
    
    bool isEmpty() const noexcept {
        return size_ == 0;
    }
    
    bool isFull() const noexcept {
        return size_ == q_.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */