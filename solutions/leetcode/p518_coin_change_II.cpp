typedef long long ll;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = (int)coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount+1, 0));
        
        for(int j=0; j<=amount; ++j){
            if(j % coins[0] == 0){
                dp[0][j] = 1;
            }
        }

        for(int i=1; i<n; ++i){
            dp[i][0]=1;
            for(int j=1; j<=amount; ++j){
                dp[i][j] = dp[i-1][j];
                if(j-coins[i]<0){
                    continue;
                }
                else {
                    dp[i][j] += dp[i][j-coins[i]];
                }

                if(dp[i][j] > INT_MAX){
                    return 0;
                }
            }
        }
        return dp[n-1][amount];
    }
};

// build up count of ways to obtain number
// since it is combinations not permutations we require at least two rows
// cannot add curr and prev j-coins[j]