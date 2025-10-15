class HitCounter {
private:
    std::deque<pair<int,int>> q_{};
    int hits_{0};

public:
    HitCounter() {}
    
    void hit(int timestamp) {
        if (!q_.empty() && q_.back().first == timestamp) {
            q_.back().second++;
        } else {
            q_.push_back({timestamp, 1});
        }
        hits_++;
    }
    
    int getHits(int timestamp) {
        while(!q_.empty() && q_.front().first <= timestamp-300) {
            hits_ -= q_.front().second;
            q_.pop_front();
        }
        return hits_;
    }
};

// by grouping together the same timestamp in q we only use O(k) time and space, where k is number of UNIQUE timestamps, rather than O(n)

// timestamp guarenteed increasing including for getHits
// therefore sliding window
// remove any hits that are timestamp-300 away

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */