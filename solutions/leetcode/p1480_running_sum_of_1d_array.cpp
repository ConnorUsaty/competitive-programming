class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        for(int i=1; i<n; ++i){
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};