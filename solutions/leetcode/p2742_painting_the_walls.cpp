class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        long long inf = 1e9;
        vector<vector<int>> dp(n+1, vector<int>(n+1, inf));

        for(int i=0;i<n+1;++i) dp[i][0] = 0;

        for(int i=1;i<n+1;++i){
            for(int j=1;j<n+1;++j){
                int not_take = dp[i-1][j];
                int take = dp[i-1][max(j-time[i-1]-1, 0)] + cost[i-1];
                dp[i][j] = min(take, not_take);
            }
        }

        return dp[n][n];
    }
};

// Have to max sure to stay within index bounds of all arrays
// This means accessing cost and time through i-1
// As well as taking the max of zero and the time earned
