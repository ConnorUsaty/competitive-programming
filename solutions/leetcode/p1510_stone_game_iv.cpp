class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; ++i){
            for(int j=1; j*j<=i; ++j){
                if(!dp[i - j*j]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// if you can force the other player into a losing state, you are in a winning state