class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int n = (int)nums.size();

        int mx_sum=0, mn_sum=0, ans=0;
        for(int i=0; i<n; ++i){
            mx_sum += nums[i];
            mn_sum += nums[i];
            ans = max({ans, mx_sum, -1*mn_sum});
            mx_sum = max(0, mx_sum);
            mn_sum = min(0, mn_sum);
        }
        return ans;
    }
};

// keep a mx_sum and a mn_sum
// use kadanes to get mx and mn sums
// return max(mx_sum, abs(mn_sum));

// for almost any subarray sum problem we can use kadanes for O(n) time, O(1) space
// remmeber to update ans before updating sums
// remember to check for edge cases such as whether empty subarrays are allowed