class MinStack {
private:
    stack<int> mn_;
    stack<int> stk_;

public:
    MinStack() {}
    
    void push(int val) {
        if(stk_.empty()){
            stk_.push(val);
            mn_.push(val);
        }
        else{
            stk_.push(val);
            if(mn_.top() > val) mn_.push(val);
            else mn_.push(mn_.top());
        }
    }
    
    void pop() {
        stk_.pop();
        mn_.pop();
    }
    
    int top() {
        return stk_.top();
    }
    
    int getMin() {
        return mn_.top();
    }
};

/**
    * Your MinStack object will be instantiated and called as such:
    * MinStack* obj = new MinStack();
    * obj->push(val);
    * obj->pop();
    * int param_3 = obj->top();
    * int param_4 = obj->getMin();
    */