class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();++i){
            // Remove element that is outside of window
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();

            // Remove any elements in window that are smaller than curr
            // Since max is at front have to remove from end to begin to ensure all smaller elements are removed
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();

            // Push curr to queue and add current highest element to answer
            dq.push_back(i);
            if (i-k+1>=0) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// deque<type> to create double ended queue in c++
// can push and pop from both ends as well as check the elements at both ends
// need to check if queue is empty before calling front() or back(), o.w. will experience undefined behaviour if deque empty