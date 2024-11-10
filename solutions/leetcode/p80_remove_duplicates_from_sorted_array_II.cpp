class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for (int n : nums) {
            if (j<2 || n>nums[j-2]) {
                nums[j] = n;
                j++;
            }
        }
        return j;
    }
};