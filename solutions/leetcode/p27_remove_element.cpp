class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0, r=nums.size()-1;

        while (l<=r) {
            if (nums[l]!=val){
                l++;
            }
            else if (nums[r]==val){
                r--;
            }
            else {
                swap(nums[l++],nums[r--]);
            }
        }
        return l;
    }
};