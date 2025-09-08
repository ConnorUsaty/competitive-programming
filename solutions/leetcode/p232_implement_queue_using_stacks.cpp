class MyQueue {
private:
    std::stack<int> psh_stk_{};
    std::stack<int> pop_stk_{};

    void shift_elements_to_pop() {
        while(!psh_stk_.empty()) {
            pop_stk_.push(psh_stk_.top());
            psh_stk_.pop();
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        psh_stk_.push(x);
    }
    
    int pop() {
        if(pop_stk_.empty()) {
            shift_elements_to_pop();
        }
        int res = pop_stk_.top();
        pop_stk_.pop();
        return res;
    }
    
    int peek() {
        if(pop_stk_.empty()) {
            shift_elements_to_pop();
        }
        return pop_stk_.top();
    }
    
    bool empty() {
        return pop_stk_.empty() && psh_stk_.empty();
    }
};

// good problem
// thought about all options outloud
// thought about complexities and design trade offs
// make sure to also think about AMORTIZED options
// in certain problems including this amortized is the optimal soln

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */