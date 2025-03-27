class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=(int)matrix.size(), m=(int)matrix[0].size(), ans=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};

// have to build up to a max and no clear greedy solution -> DYNAMIC PROGRAMMING
// each idx is bottom right of a square of size x+1 if min(left, left and above, above) = x
// HAVE to use dp vector of ints instead of modifying matrix in place BECAUSE matrix is type char therefore can only store up to digit '9'