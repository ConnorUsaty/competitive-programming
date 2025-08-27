class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int n = (int)nums.size();

        int l=0, ans = 0;
        deque<int> mx_q, mn_q;
        for(int r=0; r<n; ++r) {
            while(!mx_q.empty() && nums[mx_q.back()] < nums[r]) mx_q.pop_back();
            mx_q.push_back(r);
            while(!mn_q.empty() && nums[mn_q.back()] > nums[r]) mn_q.pop_back();
            mn_q.push_back(r);

            while(!mx_q.empty() && !mn_q.empty() && nums[mx_q.front()] - nums[mn_q.front()] > limit) {
                if (mx_q.front() < mn_q.front()){
                    l = mx_q.front() + 1;
                    mx_q.pop_front();
                } else {
                    l = mn_q.front() + 1;
                    mn_q.pop_front();
                }
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};