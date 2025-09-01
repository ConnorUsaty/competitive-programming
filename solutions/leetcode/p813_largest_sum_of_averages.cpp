class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        vector<int> p_sum(n+1, 0);
        for(int i=1; i<=n; ++i) {
            p_sum[i] = p_sum[i-1] + nums[i-1];
        }

        vector<vector<double>> dp(n, vector<double>(k, 0.0));
        for(int end=0; end<n; ++end) {
            for(int partition=0; partition<=min(end,k-1); ++partition) {
                int min_start = (partition == 0) ? 0 : partition;
                for(int start=end; start>=min_start; --start) {
                    if(partition == 0 && start > 0) continue;
                    double part_score = (p_sum[end+1] - p_sum[start]) / (end-start+1.0);
                    double prev_score = (start>0 && partition>0 ? dp[start-1][partition-1] : 0);
                    dp[end][partition] = max(dp[end][partition], prev_score + part_score);
                }
            }
        }
        return dp[n-1][k-1]; 
    }
};

// NEED to loop like this: end, part, start
// to properly build up dp[end][part]

// we can make p_sum to get sums in O(1)
// we will need to try every parition -> O(n^2 * k)
// dp[end][k] = score after ending parition k on [end]

// parition array into AT MOST k subarrays
// score of each parition = sum(avg of paritions)
// return max score acheivable