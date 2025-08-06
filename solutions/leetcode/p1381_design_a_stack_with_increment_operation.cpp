class CustomStack {
private:
    size_t capacity_;
    stack<int> stk_{};
    vector<int> inc_;

public:
    CustomStack(int maxSize) : capacity_(maxSize), inc_(maxSize, 0) {}
    
    void push(int x) {
        if(stk_.size() < capacity_){
            stk_.push(x);
        }
    }
    
    int pop() {
        if(stk_.empty()) return -1;
        
        int res = stk_.top();
        stk_.pop();
        if(inc_[stk_.size()] > 0){
            res  += inc_[stk_.size()];
            if(stk_.size() > 0){
                inc_[stk_.size()-1] += inc_[stk_.size()];
            }
            inc_[stk_.size()] = 0;
        }
        return res;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)stk_.size());
        if(k != 0){
            inc_[k-1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */