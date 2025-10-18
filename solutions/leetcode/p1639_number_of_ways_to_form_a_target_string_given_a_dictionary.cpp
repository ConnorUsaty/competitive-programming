class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int n = static_cast<int>(words[0].size());
        const int m = static_cast<int>(target.size());
        const int MOD = 1e9+7;

        vector<vector<long long>> cnt(n, vector<long long>(26, 0));
        for(const std::string& s : words) {
            for(int i=0; i<n; ++i) {
                cnt[i][s[i]-'a']++;
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; ++i) dp[i][0] = 1;

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = (dp[i][j] + cnt[i-1][target[j-1]-'a'] * dp[i-1][j-1]) % MOD;
            }
        }
        return dp[n][m];
    }
};

// strings are all SAME len

// target[i] = words[j][k] can be used iff match
// when we use words[j][k] can NO longer use the any char at [x], where x <= k

