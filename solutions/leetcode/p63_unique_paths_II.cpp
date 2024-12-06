class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp(obstacleGrid[0].size(), 0);
        dp[0]=1;
        for(int i=0;i<obstacleGrid.size();++i){
            if(obstacleGrid[i][0]==1) dp[0]=0;
            for(int j=1;j<obstacleGrid[0].size();++j){
                if(obstacleGrid[i][j]==0){
                    dp[j] += dp[j-1];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[obstacleGrid[0].size()-1];
    }
};

// At each square the number of paths to it is the sum of paths from the left and from above, start at top left or bottom right and build up your answer