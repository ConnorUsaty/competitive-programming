class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l<=r){
            int m = l+ (r-l)/2;

            if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return l;
    }
};

// use while (l<=r) for binary search, use r for else to push r over l, then return l
// use int m = l + (r-l)/2; to prevent overflow of (r+l)
// use while (l<r) for two ptrs