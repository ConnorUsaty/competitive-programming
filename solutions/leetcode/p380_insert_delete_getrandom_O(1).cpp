class RandomizedSet {
private:
    unordered_map<int,int> _mp;
    vector<int> _vec;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(_mp.find(val) != _mp.end()) return false;

        _mp[val] = (int)_vec.size();
        _vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(_mp.find(val) == _mp.end()) return false;

        int idx = _mp[val];
        std::swap(_vec[_vec.size()-1], _vec[idx]);
        _vec.pop_back();
        _mp[_vec[idx]] = idx; // have to do before erase incase only element
        _mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return _vec[rand() % _vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */