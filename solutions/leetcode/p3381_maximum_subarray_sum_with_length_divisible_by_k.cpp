class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        vector<long long> dp(n, 0);
        long long ans = LLONG_MIN, curr=0;

        for(int i=0; i<k; ++i){
            curr += nums[i];
        }
        dp[k-1] = curr;
        ans = curr;

        for(int i=k; i<n; ++i){
            curr -= 1LL*nums[i-k];
            curr += 1LL*nums[i];
            dp[i] = max(curr, curr + dp[i-k]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// house robber + kadanes ?
// you try to add the sum of the last k to the best ans at [i-k]
// update ans every iter
// if sum or [i-k] option < 0, reset to 0

// NEED to update ans before resetting curr