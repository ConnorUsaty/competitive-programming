class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // dp[i][j] i = subset of first i walls, j = walls completed
        // i belongs to [0, cost.size()]
        // j belongs to [0, cost.size()]
        // dp[i][j] stores min cost to complete j walls with subset of first i walls
        // at each [i][j] take best solution out of [i-1][j-cost] and [i][j-1]

        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));

        // initialize base case of 0 walls complete
        for(int i=0;i<n;++i) dp[i][0] = 0; // 0 cost to complete 0 walls

        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int not_take = dp[i-1][j]; // cost of prev subset solution 
                int take = dp[i-1][max(j-time[i-1]-1, 0)] + cost[i-1]; // cost of taking item
                dp[i][j] = min(not_take, take); // take min cost
            }
        }

        return dp[n][n];
    }
};

// dp
// come up with subsets to build up from / bounds for dp arr
// initialize base cases
// iterate through and build up from base cases to final solution