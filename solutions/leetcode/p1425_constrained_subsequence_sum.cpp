class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        int ans = INT_MIN;
        vector<int> dp(n);
        deque<int> q;
        for(int i=0; i<n; ++i){
            if(!q.empty() && i-q.front() > k) {
                q.pop_front();
            }

            dp[i] = (!q.empty() ? dp[q.front()] : 0) + nums[i];

            while(!q.empty() && dp[q.back()] < dp[i]) {
                q.pop_back();
            }
            if(dp[i] > 0) {
                q.push_back(i);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// subsequence does NOT always mean dp -> that would give us O(n*k) time which will TLE

// we only ever want to add onto the MAX possible sum in the last k values
// we can maintain the max possible sum in the last k values using a monotonic queue (sliding window)
// now we know the max in window in O(1)
// thus our solution is O(n) time
// O(n) space