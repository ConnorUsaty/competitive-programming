class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();

        int ans = 1;
        vector<vector<int>> dp(2, vector<int>(n,1));
        for(int i=1; i<n; ++i){
            if(nums1[i]>=nums2[i-1]){
                dp[0][i] = dp[1][i-1] + 1;
            }
            if(nums1[i]>=nums1[i-1]){
                dp[0][i] = max(dp[0][i], dp[0][i-1]+1);
            }
            if(nums2[i]>=nums2[i-1]){
                dp[1][i] = dp[1][i-1] + 1;
            }
            if(nums2[i]>=nums1[i-1]){
                dp[1][i] = max(dp[1][i], dp[0][i-1]+1);
            }
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        return ans;
    }
};