class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        const int n = (int)nums1.size();

        int ans = 1;
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        for(int i=1; i<n; ++i) {
            if(nums1[i]>=nums1[i-1]){
                dp1[i] = max(dp1[i], dp1[i-1] + 1);
            }
            if(nums1[i]>=nums2[i-1]){
                dp1[i] = max(dp1[i], dp2[i-1] + 1);
            }
            if(nums2[i]>=nums2[i-1]){
                dp2[i] = max(dp2[i], dp2[i-1] + 1);
            }
            if(nums2[i]>=nums1[i-1]){
                dp2[i] = max(dp2[i], dp1[i-1] + 1);
            }
            ans = max({ans, dp1[i], dp2[i]});
        }
        return ans;
    }
};

// remember to look for space optimizations on DP problems
// i.e. here we only ever look back 1 idx so we should only need O(1) space not O(n)

// max len >= subarray

// always choose min value for [0]
// this logic doesn't continue for all i indexes though
// keep 2 dp arrays
// dp1[i] = max len subarray ending on nums1[i]
// dp2[i] = max len subarray ending on nums2[i]
// this covers both possible options and thus our ans is the max that we encounter