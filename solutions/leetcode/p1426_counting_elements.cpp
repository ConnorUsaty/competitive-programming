class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_map<int,int> cnt;
        for(const int& a : arr) {
            cnt[a]++;
        }

        int ans = 0;
        for(auto& [n, freq] : cnt) {
            if(cnt.find(n+1) != cnt.end()) {
                ans += freq;
            }
        }
        return ans;
    }
};

// O(n + k) time, where n = num elements and k = unique elements
// O(k) space
