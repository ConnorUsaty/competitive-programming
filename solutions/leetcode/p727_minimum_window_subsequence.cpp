class Solution {
    public:
        string minWindow(string s1, string s2) {
            int n=(int)s1.size(), m=(int)s2.size();
            vector<vector<int>> dp(n, vector<int>(m, n+1));
    
            // init base case
            int last = -1;
            for(int i=0; i<n; ++i){
                if(s1[i]==s2[0]) last = i;
                dp[i][0] = (last==-1) ? dp[i][0] : i-last+1;
            }
    
            // build up solution
            for(int j=1; j<m; ++j){
                last = -1;
                for(int i=j; i<n; ++i){
                    if(s1[i]==s2[j]) last = i;
                    dp[i][j] = (last==-1) ? dp[i][j] : dp[last-1][j-1]+i-last+1;
                }
            }
    
            // get min
            int len = n+1;
            int idx = -1;
            for(int i=m-1; i<n; ++i){
                if(dp[i][m-1]<len){
                    len = dp[i][m-1];
                    idx = i-len+1;
                }
            }
            
            // cover edge case
            return (len<=n) ? s1.substr(idx, len) : "";
        }
    };
    
    // subsequence / building up solution -> DYNAMIC PROGRAMMING
    // dp[i][j] = shortest substr len that ends on [i] that includes first j chars 
    // since we want shortest init dp with inf