class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> cnt;
        for(int n : nums) cnt[n]++;

        vector<pair<int,int>> freq;
        for(const auto& it : cnt) freq.push_back({it.second,it.first});
        sort(freq.begin(), freq.end());

        vector<int> ans;
        for(int i=0;i<k;++i) ans.push_back(freq[freq.size()-1-i].second);
        
        return ans;
    }
};

// problems that can be solved with sorting or heaps or counting can often be optimized with hashmaps or hashsets
// sometimes even possible to use only arrays / vectors when given exact constraints
// C++ sorts in ascending order by default, can pass .rbegin() and .rend() instead to get ascending order
