class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        deque<pair<int,int>> q;

        for (int i=0; i<n; ++i) {
            if (!q.empty() && i-q.front().first > k) {
                q.pop_front();
            }
            int v = nums[i] + (q.empty() ? 0 : q.front().second);
            while (!q.empty() && q.back().second < v) {
                q.pop_back();
            }
            q.push_back({i, v});
        }
        return q.back().second;
    }
};

// pretty standard monotonic q problem
// we should only ever use the max score from the last k idx as our last jump
// naturally we can track this easily and "query" the max in O(1) with a monotonic queue
// resulting in a O(n) time, O(k) space solution

// greedily visit all nums[i] >= 0
// when nums[i] < 0 
// just keep track of max score in last k to solve both cases
// O(n) time, O(k) space -> monotonic queue

// u want to reach [n-1]
// score = sum(all nums visited)
// can jump at most k steps forward

// return MAX SCORE

// to maximize score land on as many positive nums as possible
// land on as few and < neg nums as possible