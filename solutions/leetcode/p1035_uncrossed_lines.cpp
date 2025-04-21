class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=(int)nums1.size();
        int n2=(int)nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); 

        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

// we can conclude easily that a greedy approach (always connecting values that are close together) would not work with a counter example
// EX: we could match the first 5 values of nums1 with the last 5 values of nums2 therefore 5 connections, BUT we greedily connected in the middle of the arrays
// at some idx i = j, where 0 <= i = j < n, therefore ruining the 5 connections, giving us 1 connection, therefore WA (wrong answer)

// since we have concluded a greedy approach does not work we now consider that we have the option to either make the connection or NOT make the connection whenever we find two matching numbers
// this immediately leads us to realize we should use DYNAMIC PROGRAMMING
// we can find how many connections are possible using only values up to [i][j], where i is idx of nums1 and j is idx of nums2
// then when we find a match we take the max(use match(make connection), dont use match(dont connect))
// by the end our answer will be at dp[n][n]