class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n = (int)nums.size();

        long long ans = 0, l = 0;
        deque<int> mn, mx;
        for(int r=0; r<n; ++r){
            while(!mn.empty() && nums[mn.back()] > nums[r]){
                mn.pop_back();
            }
            mn.push_back(r);

            while(!mx.empty() && nums[mx.back()] < nums[r]){
                mx.pop_back();
            }
            mx.push_back(r);

            while(!mn.empty() && !mx.empty() && nums[mx.front()]-nums[mn.front()] > 2){
                if(mx.front() < mn.front()){
                    l = mx.front() + 1;
                    mx.pop_front();
                } else {
                    l = mn.front() + 1;
                    mn.pop_front();
                }
            }
            ans += r-l+1;
        }
        return ans;
    }
};

// sliding window, make sure window_mx - window_mn <= 2
// keep track of mn and mx in window with monotonic queues