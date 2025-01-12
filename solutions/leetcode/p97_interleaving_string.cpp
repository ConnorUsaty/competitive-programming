class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length()+2, vector<int>(s2.length()+2, 0));
        dp[0][0] = 1;

        for(int i=0; i<=s1.length(); ++i){
            for(int j=0; j<=s2.length(); ++j){
                if(dp[i][j] && s1[i]==s3[i+j]){
                    dp[i+1][j] = 1;
                }
                if(dp[i][j] && s2[j]==s3[i+j]){
                    dp[i][j+1] = 1;
                }
            }
        }

        return dp[s1.length()+1][s2.length()] && dp[s1.length()][s2.length()+1];
    }
};

// can build up an array by checking if the previous required build up was possible
// then at each step check if we can progress either or both of our ptrs across s1 and s2