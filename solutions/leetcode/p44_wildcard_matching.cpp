class Solution {
public:
    bool isMatch(string s, string p) {
        int n=(int)s.size(), m=(int)p.size();

        if(n==0){
            for(const char& c : p) if(c!='*') return false;
            return true;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0]=1;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(dp[i-1][j-1]){
                    if(s[i-1]==p[j-1] || p[j-1]=='?'){
                        dp[i][j]=1;
                    }
                    if(p[j-1]=='*'){
                        // can be empty sequence
                        dp[i][j]=1;
                        dp[i-1][j]=1;
                    }
                }
                if(p[j-1]=='*' && (dp[i-1][j] || dp[i][j-1])){
                    dp[i][j]=1;
                }
            }
        }
        return dp[n][m];
    }
};

// dp[i][j] means we can get to [i-1] in s using up to [j-1] in pattern

// to continue making progress have to either be valid at [i-1][j-1] and a match or '?'
// OR pattern[j] == '*' and then we can either skip over it or continue