using pii = pair<int,int>;

class LRUCache {
private:
    std::list<pii> list_{}; // {key, val}
    std::unordered_map<int, std::list<pii>::iterator> mp_{}; // {key, LL iter}
    size_t cap_;

public:
    LRUCache(int capacity) : cap_(capacity) {}
    
    int get(int key) {
        auto it = mp_.find(key);
        if(it == mp_.end()) {
            return -1;
        }

        // key exists, we must update this to be the most recently accessed
        list_.splice(list_.end(), list_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp_.find(key);
        if(it == mp_.end()) {
            if(mp_.size() == cap_) {
                // remove LRU element
                auto lru_it = list_.begin();
                mp_.erase(lru_it->first);
                list_.pop_front();
            }
            // insert new element
            list_.push_back({key, value});
        }
        else {
            // update val of existing
            list_.splice(list_.end(), list_, it->second);
            list_.back().second = value;
        }
        auto back_it = std::prev(list_.end());
        mp_[key] = back_it;
    }
};

// check for existance, add, or update val in amoritzed O(1) with unordered_map
// to evict from LRU in O(1) we can maintain a LL that is in order of usage
// must store iterator to LL in map to move around in O(1)

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */