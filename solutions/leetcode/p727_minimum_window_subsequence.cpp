class Solution {
public:
    string minWindow(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, n+1));
        dp[0][0] = 0;

        int end=0, length=n+1;
        for (int i=1; i<=n; ++i) {
            dp[i][0] = 0;
            for (int j=1; j<=m; ++j) {
                dp[i][j] = 1 + (s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j]);
            }
            if (dp[i][m] < length) {
                length = dp[i][m];
                end = i;
            }
        }
        return (length > n) ? "" : s1.substr(end - length, length);
    }
};

// subsequence property -> DYNAMIC PROGRAMMING
// build up from base case by going through the letters in substr s2