class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return -1 if not in nums
        // must solve in O(logn) -> binary search
        // perform 2 binary searchs, one to find pivot / original idx [0]
        // one to search the correct side of pivot for target

        int l=0, r=nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m] > nums[r]) {
                // pivot must be on right of m
                l = m+1;
            }
            else {
                r = m;
            }
        }
        int piv = l;

        if(target>nums[nums.size()-1]){
            l=0; r=piv;
        } else {
            l=piv; r=nums.size()-1;
        }
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]<target){
                l=m+1;
            } else {
                r=m-1;
            }
        }
        if(l>=nums.size() || nums[l]!=target) return -1;
        return l;
    }
};

// on first binary search have to use r=m and l<r instead of r=m-1 and l<=r, because we cannot be sure that the current m value is not the pivot
// on second one we can search as normal because we are sure that the current m is not the target or that l is already on the target when we change r
// need to cover edge cases at end where l not valid index or nums[l]!= target, both of these mean that target is not in nums
