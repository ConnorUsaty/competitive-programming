class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = (int)nums.size();

        unordered_map<int,int> cnt;
        for(int i=0; i<n; ++i) {
            ++cnt[nums[i]];
        }
        int mx = -1;
        for(auto& [key, val] : cnt) {
            mx = max(mx, val);
        }

        int ans = max(0, mx - (n-mx));
        if(ans==0 && n&1) ans++;
        return ans;
    }
};

// ans = cnt of most freq - cnt of rest