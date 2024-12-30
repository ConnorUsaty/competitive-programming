class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0, ans=-INT_MAX;
        for(const int& n : nums){
            curr += n;
            ans = max(ans, curr);
            curr = max(curr, 0);
        }
        return ans;
    }
};


// Use Kadane's greedy algorithm
// if our curr sum ever goes < 0 it is always better to restart from next element therefore reset
// keep track of current max encountered at each iteration / index

// even when curr < 0 need to check if curr is ans, due to case of only neg n in nums
