class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // Intialize the base case
        for(int i=1; i<=min(k,target); ++i) dp[1][i] = 1;
        
        for (int dice=2; dice<=n; ++dice) {
            for (int currSum=dice; currSum<=target; ++currSum) {
                int ways = 0;
                for (int i=1; i<=min(k, currSum); ++i) {
                    ways = (ways + dp[dice-1][currSum-i]) % MOD;
                }
                dp[dice][currSum] = ways;
                if(ways == 0) break;
            }
        }
        return dp[n][target];
    }
};

// building up answer / combinations counting -> DYNAMIC PROGRAMMING