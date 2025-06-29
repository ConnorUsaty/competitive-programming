class Solution{
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        dp[n][0] = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=k; j++) {
                int curr = 0;
                for(int p=i; p<n; p++) {
                    curr ^= nums[p];
                    if(dp[p+1][j-1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], max(dp[p+1][j-1], curr));
                    }
                }
            }
        }
        return dp[0][k];
    }
};