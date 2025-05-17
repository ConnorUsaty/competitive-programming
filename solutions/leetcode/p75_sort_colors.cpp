class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, l=0, r=(int)nums.size()-1;

        while(i<=r){
            if(nums[i]==2){
                swap(nums[r],nums[i]);
                r--;
            }
            if(nums[i]==0){
                swap(nums[l],nums[i]);
                l++;
                i = (i<l ? l : i);
            }
            if(i<=r && nums[i]==1){
                i++;
            }
        }
    }
};

// this is just the dutch flag problem