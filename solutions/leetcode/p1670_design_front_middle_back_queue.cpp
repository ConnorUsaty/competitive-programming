class FrontMiddleBackQueue {
private:
    deque<int> a, b;
    int elements;

public:
    FrontMiddleBackQueue() {
        elements = 0;
    }
    
    void pushFront(int val) {
        if(elements&1 && !a.empty()){
            b.push_front(a.back());
            a.pop_back();
        }
        a.push_front(val);
        elements++;
    }
    
    void pushMiddle(int val) {
        if(elements&1 && !a.empty()){
            b.push_front(a.back());
            a.pop_back();
        }
        a.push_back(val);
        elements++;
    }
    
    void pushBack(int val) {
        while(elements && b.size()>=a.size()){
            a.push_back(b.front());
            b.pop_front();
        }
        b.push_back(val);
        elements++;
    }
    
    int popFront() {
        if(elements==0){
            return -1;
        }
        if(a.empty()){
            int res = b.front();
            b.pop_front();
            elements--; 
            return res;
        }

        if(!(elements&1) && !b.empty()){
            a.push_back(b.front());
            b.pop_front();
        }
        int res = a.front();
        a.pop_front();
        elements--;
        return res;
    }
    
    int popMiddle() {
        if(elements==0){
            return -1;
        }
        if(a.empty()){
            int res = b.front();
            b.pop_front();
            elements--;
            return res;
        }

        int res = a.back();
        a.pop_back();
        elements--;
        if(elements&1 && !b.empty()){
            a.push_back(b.front());
            b.pop_front();
        }
        return res;
    }
    
    int popBack() {
        if(elements==0){
            return -1;
        }
        if(b.empty()){
            int res = a.back();
            a.pop_back();
            elements--; 
            return res;
        }

        int res = b.back();
        b.pop_back();
        elements--;
        if(!(elements&1) && !a.empty()){
            b.push_front(a.back());
            a.pop_back();
        }
        return res;
    }
};

// can two deques to split in half and query middle in O(1)
// need to ensure ordering of middle or first middle being a.back() is always kept

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */