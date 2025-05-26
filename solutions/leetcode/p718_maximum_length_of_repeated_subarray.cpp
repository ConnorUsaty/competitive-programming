class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=static_cast<int>(nums1.size()), m=static_cast<int>(nums2.size());
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;
        for(int i=0; i<m; ++i){
            if(nums1[0]==nums2[i]){
                dp[0][i]=1;
                ans=1;
            }
        }

        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(nums1[i]==nums2[j]){
                    // can continue subarray
                    if(j>0){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// similar to LCS but its a contiguous subarray not SS, therefore we can only continue and build if =, else we keep to 0, we dont take the best of i-1, j-1;