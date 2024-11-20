class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int t=0;
        for(int i=0;i<nums.size();++i) {
            t = max(t,i);
            while(t<nums.size() && nums[t]==0){
                t++;
            }
            if(i!=t && t<nums.size()) swap(nums[i],nums[t]);
        }
    }
};