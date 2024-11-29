class RecentCounter {
private:
    deque<int> reqs;

public:
    RecentCounter() {}
    
    int ping(int t) {
        while(!reqs.empty() && reqs.front() < (t-3000)) reqs.pop_front();
        reqs.push_back(t);
        return reqs.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */