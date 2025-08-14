class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k+1, vector<int>(n, -1e9));
        for(int i=0; i<n; ++i) dp[0][i] = 0;

        for(int i=1; i<=k; ++i){
            for(int j=0; j<n; ++j){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + stayScore[i-1][j]);
                for(int l=0; l<n; ++l){
                    dp[i][j] = max(dp[i][j], dp[i-1][l] + travelScore[l][j]);
                }
            }
        }
        return *max_element(dp[k].begin(), dp[k].end());
    }
};

// dp[day][city] = max pts