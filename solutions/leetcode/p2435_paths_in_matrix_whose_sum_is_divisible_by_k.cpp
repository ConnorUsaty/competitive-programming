class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9+7;
        const int m = (int)grid.size();
        const int n = (int)grid[0].size();

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k, 0)));
        dp[0][1][0] = 1;
        
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                int offset = grid[i-1][j-1];
                for(int l=0; l<k; ++l) {
                    dp[i][j][(l+offset)%k] = (dp[i-1][j][l] + dp[i][j-1][l]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};

// dp[i][j][k] -> track amount of paths to [i][j] that sum to [%k]

// when tracking a number of something thats divisible by k, we can normally just track the count of every res % k, assuming k is small that is minimal time and space

// need to remember to set base case and to set =
// cannot do +=, as we will overcount
// problems like this where we only ever index into the row above or col before can be space optimized 
