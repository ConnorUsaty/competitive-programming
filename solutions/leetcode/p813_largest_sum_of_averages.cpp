class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        vector<double> p_sum(n+1, 0.0);
        for (int i=0; i<n; ++i) {
            p_sum[i+1] = p_sum[i] + nums[i];
        }
        
        // dp[i][j] = max sum of averages for first i elements split into j groups
        vector<vector<double>> dp(n+1, vector<double>(k+1, -1e9));
        dp[0][0] = 0;
        
        for (int end=1; end<=n; ++end) {
            for (int group=1; group<=min(end, k); ++group) {
                for (int start=group-1; start<end; ++start) {
                    double sum = p_sum[end] - p_sum[start];
                    double avg = sum / (end - start);
                    dp[end][group] = max(dp[end][group], dp[start][group-1] + avg);
                }
            }
        }
        
        return dp[n][k];
    }
};

// for parition problems we have to check each possible parition point resulting in 3 nested loops for group, start, end
// can use prefix sum to efficiently calculates range sums / avg