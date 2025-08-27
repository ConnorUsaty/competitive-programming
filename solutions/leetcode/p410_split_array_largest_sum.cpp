class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        vector<int> p_sum(n+1, 0);
        for(int i=1; i<=n; ++i){
            p_sum[i] = p_sum[i-1] + nums[i-1];
        }

        vector<vector<long long>> dp(n+1, vector<long long>(k+1, LLONG_MAX));
        dp[0][0] = 0;
        for(int end=1; end<=n; ++end) {
            for(int group=1; group<=min(end,k); ++group) {
                for(int start=group-1; start<end; ++start) {
                    long long sm = p_sum[end] - p_sum[start];
                    long long mx = max(dp[start][group-1], sm);
                    dp[end][group] = min(dp[end][group], mx);
                }
            }
        }
        return dp[n][k];
    }
};

// precompute prefix sums to do start to end sums in O(1)

// dp[i][j] = minimum sum with j'th subarray ending on [i]

// 3 loops, start, end, k
// O(n^2 * k) time
// O(n * k) space