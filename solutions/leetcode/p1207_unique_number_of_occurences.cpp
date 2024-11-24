class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> cnt;
        for(const int& n : arr) cnt[n]++;

        set<int> seen;
        for(const auto& it : cnt){
            if(seen.find(it.second)!=seen.end()){
                return false;
            }
            else {
                seen.insert(it.second);
            }
        }
        return true;
    }
};