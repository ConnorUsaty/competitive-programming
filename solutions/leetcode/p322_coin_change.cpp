class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // init dp array with proper values for solution
        vector<int> dp(amount+1, 1e9);
        dp[0]=0;

        // at each amount check the minimum amount of coins required to reach that amount
        for(int i=1; i<=amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(i-coins[j]>=0){
                    // if possible to get to this amount using this coin
                    // check if better to use prev solution or use this coin
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }

        // if dp[amount] = init value, then it is not possible to reach that amount with these coins
        return (dp[amount]==1e9) ? -1 : dp[amount];
    }
};

// For DP:
// 1. Identify problem
// 2. Identify subproblems
// 3. Identify base case
// 4. How to build on solutions

// Easy to start by thinking how would I solve this with minimum constraints, i.e. 1 coin and amount of 1