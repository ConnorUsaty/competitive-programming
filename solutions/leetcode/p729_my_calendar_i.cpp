class MyCalendar {
private:
    std::map<int,int> calendar_{}; // {time}

public:
    MyCalendar() {} 
    
    bool book(int startTime, int endTime) {
        auto lb = calendar_.lower_bound(startTime);
        if(lb == calendar_.end() || lb->first>=endTime && lb->second>=endTime) {
            calendar_.insert({startTime, endTime-1});
            calendar_.insert({endTime-1, startTime});
            return true;
        }
        return false;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

// for std::set and std::map use *::lowerbound(target)
// O(logn) insertions, erases, and searches
// both are Red-Black Trees under the hood (self-balancing)