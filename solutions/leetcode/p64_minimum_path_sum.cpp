class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<long long> dp(grid[0].size(), LLONG_MAX);
        dp[0]=0;
        for(int i=0;i<grid.size();++i){
            dp[0]+=grid[i][0];
            for(int j=1;j<grid[0].size();++j){
                dp[j] = min(dp[j],dp[j-1]) + grid[i][j];
            }
        }
        return dp[grid[0].size()-1];
    }
};

// can only come from left or above
// therefore take min(left,above) and + curr square val

// for all these problems where you can only move down or right, build up solution by taking the best option out of left and top
// LLONG_MAX gives you the max long long val in cpp
// even though these paths have a 2D input, the dp vector only needs to be 1D as we only ever need the prev and curr rows
// init the dp vector with the values needed for the base cases, set dp[0] seperately if needed
// use long longs because sums can become large even when individual values all fit in int type