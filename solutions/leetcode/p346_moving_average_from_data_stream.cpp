class MovingAverage {
public:
    MovingAverage(int size) : cap_(size) {}
    
    double next(int val) {
        q_.push(val);
        sm_ += val;
        if(q_.size() > cap_){
            sm_ -= q_.front();
            q_.pop();
        }
        return static_cast<double>(sm_) / static_cast<double>(q_.size());
    }

private:
    size_t cap_;
    int sm_ = 0;
    queue<int> q_{};
};

// maintain sm_, cap_, and q_
// if q_.size() > cap_, pop_front() and sm_ -= q.front()
// return sm_ / q.size() -> must be in double

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */