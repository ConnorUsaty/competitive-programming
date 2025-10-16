class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int n = nums.size();

        vector<unordered_map<int,int>> dp(k+1);
        vector<int> res(k+1, 0);
        for(const int& n : nums) {
            for(int j=k; j>=0; --j) {
                // increase current seq of this num or attach to ans
                dp[j][n] = max(dp[j][n] + 1, (j>0 ? res[j-1] : 0) + 1);
                res[j] = max(res[j], dp[j][n]);
            }
        }
        return res[k];
    }
};