class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> _mp;

public:
    TimeMap() {};
    
    void set(string key, string value, int timestamp) {
        if(_mp.find(key) == _mp.end()){
            _mp[key] = {{timestamp, value}};
        } else {
            _mp[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        if(_mp.find(key) == _mp.end()){
            return "";
        }
        vector<pair<int,string>>& search = _mp[key];
        if(search[0].first > timestamp){
            return "";
        }

        int l=0, r=search.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;

            if(search[m].first <= timestamp){
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return (l>0) ? search[l-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// since sets are strictly increasing we can just push back on set
// for get can binary search to obtain first ts <= inp ts in O(logn)