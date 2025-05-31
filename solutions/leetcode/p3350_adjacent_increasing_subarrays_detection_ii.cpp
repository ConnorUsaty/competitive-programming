class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=static_cast<int>(nums.size());

        int ans=1, curr=1;
        vector<int> dp(n, 0);
        for(int i=1; i<(int)nums.size(); ++i){
            if(nums[i]>nums[i-1]) curr++;
            else curr=1;
            dp[i]=curr;
            ans = max(ans, curr/2);
            if(i-curr>=0) ans = max(ans, min(curr, dp[i-curr]));
        }
        return ans;
    }
};

// can either be one long sequence split into two -> curr/2
// or connecting two different sequences -> min(curr, dp[i-curr])

// whenever we need to "connect" sequences or subarrays or check for a best answer at a certain index we should use a vector to store previously calculated results