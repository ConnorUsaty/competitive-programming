class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        int n=static_cast<int>(nums.size());
        vector<int> ans(n-1, 0);
        ans[0] |= nums[0];
        for(int i=1; i<n-1; ++i){
            ans[i-1] |= nums[i];
            ans[i] |= nums[i];
        }
        ans[n-2] |= nums[n-1];
        return ans;
    }
};