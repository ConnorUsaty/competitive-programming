class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        vector<int> dp(n);
        deque<int> q;
        for(int i=0; i<n; ++i) {
            while(!q.empty() && i-q.front() > k) {
                q.pop_front();
            }
            int prev = (q.empty() ? 0 : dp[q.front()]);
            dp[i] = max(nums[i], prev + nums[i]);
            while(!q.empty() && dp[q.back()] < dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// build up a non-empty subseq where adj elements idx differ by <= k
// return MAX sum possible from a subseq built that way

// obviously we build up a subseq by checking what the max possible sum we could have at [i] is
// to get max possible sum when we can only choose from last K elements, we just need to know the max in the last K
// we can keep track of this with a monotonic q

// then for each idx we simply set dp[i] = max({dp[q.front()] + nums[i], nums[i]});

// return *max_element(dp.begin(), dp.end());

// subsequence does NOT always mean dp -> that would give us O(n*k) time which will TLE

// we only ever want to add onto the MAX possible sum in the last k values
// we can maintain the max possible sum in the last k values using a monotonic queue (sliding window)
// now we know the max in window in O(1)
// thus our solution is O(n) time
// O(n) space