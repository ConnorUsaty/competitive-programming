class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int i2=0; // 2 indexes ago
        int i1=0; // 1 index ago
        for(int i=0; i<nums.size(); ++i){
            int t = i1;
            i1 = max(i1, i2+nums[i]);
            i2 = t;
        }
        return i1;
    }
};

// at each step we can either rob the house and have that money + max from i-2
// or not rob house and take money of max from i-1
// just compare these two options at each index and build up to ans

// build up entire solution through the loop, and init vars to 0, NOT to nums[0] and nums[1]