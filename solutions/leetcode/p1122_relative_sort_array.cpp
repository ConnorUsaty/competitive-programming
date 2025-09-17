class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> cnt;
        for(auto& i : arr1) cnt[i]++;

        vector<int> ans;
        ans.reserve(arr1.size());
        for(auto& a : arr2) {
            auto it = cnt.find(a);
            if(it != cnt.end()) {
                while(cnt[a]>0) {
                    ans.emplace_back(a);
                    cnt[a]--;
                }
                cnt.erase(a);
            }
        }
        for(auto& it : cnt) {
            while(it.second > 0) {
                ans.emplace_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};