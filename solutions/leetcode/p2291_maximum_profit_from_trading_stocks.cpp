class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n=(int)present.size();
        vector<vector<int>> dp(n, vector<int>(budget+1, 0));

        for(int j=0; j<= budget; ++j){
            if(j-present[0]>=0){
                dp[0][j] = max(dp[0][j], future[0]-present[0]);
            }
        }

        for(int i=1; i<n; ++i){
            for(int j=0; j<=budget; ++j){
                if(j-present[i]<0){
                    // cannot buy stock
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    // can buy stock -> check if better to buy
                    int profit = future[i]-present[i];
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-present[i]]+profit);
                }
            }
        }
        return dp[n-1][budget];
    }
};

// classic 0-1 knapsack problem
// build up subcases of first i items and budget of j
// then build upon them by checking if buying item i+1 is better or not than current solution with budget of j