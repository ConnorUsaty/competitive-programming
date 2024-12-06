class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int i=0;i<amount+1;++i){
            for(int j=0;j<coins.size();++j){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};

// For DP:
// 1. Identify problem
// 2. Identify subproblems
// 3. Identify base case
// 4. How to build on solutions

// Easy to start by thinking how would I solve this with minimum constraints, i.e. 1 coin and amount of 1