class Solution {
private:
    int robHelper(vector<int>& nums, int i, int j){
        int p1=0, p2=0;
        for(; i<j; ++i){
            int t = p1;
            p1 = max(p1, p2+nums[i]);
            p2 = t;
        }
        return p1;
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(robHelper(nums,0,(int)nums.size()-1), robHelper(nums,1,(int)nums.size()));
    }
};

// perform house robber at [0] and [1], take best of two

// remember to account for edge cases such as 0-1 houses