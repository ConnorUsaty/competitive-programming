class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=(int)stones.size();

        vector<int> p_sum(n+1, 0);
        for(int i=1; i<=n; ++i){
            p_sum[i] = p_sum[i-1] + stones[i-1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int start=n-2; start>=0; --start){
            for(int end=start+1; end<n; ++end){
                int first = p_sum[end+1]-p_sum[start+1];
                int last = p_sum[end]-p_sum[start];
                dp[start][end] = max(first-dp[start+1][end], last-dp[start][end-1]);
            }
        }
        return dp[0][n-1];
    }
};

// alice will always be greater therefore always win
// therefore to maximize difference she must get her max possible score
// bob has to do the same (maximize his possible score) to bring the difference as low as possible