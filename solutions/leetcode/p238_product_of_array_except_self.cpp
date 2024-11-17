class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        // calculate all prefix products -> [0] has to be included to properly update pre_prod
        int pre_prod=1;
        for(int i=0;i<nums.size();++i){
            ans[i] = pre_prod;
            pre_prod *= nums[i];
        }

        // calculate all suffix products -> [-1] has to be included to properly update suf_prod
        int suf_prod=1;
        for(int i=nums.size()-1;i>=0;--i){
            ans[i] *= suf_prod;
            suf_prod *= nums[i];
        }

        return ans;
    }
};

// getting total_prod and then dividing out curr element doesnt work due to edge case where array contains 0, then total_prod = 0