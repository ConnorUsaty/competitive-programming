class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(int i=1; i<nums.size(); ++i){
            for(int j=i-1; j>=0; --j){
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        // since dp[i] is LIS INCLUDING i and not up to i we have to return the max element
        // instead of return dp[n-1]
        return *max_element(dp.begin(), dp.end());
    }
};

// subsequence, should immediately signal backtracking / dp
// since we only need to track a trait of the subsequences (the longest increast ss)
// this should immediately signal dp

// let dp[i] store the LIS up until and including [i]
// at each i move backwards until u find the first element strictly smaller than nums[i]
// dp[i] = dp[j] + 1, where nums[j] is the first < nums[i]