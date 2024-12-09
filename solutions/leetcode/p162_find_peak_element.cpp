class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(m==nums.size()-1) break;

            if(nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return l;
    }
};

// use binary search with condition on neighbour to find a peak
// use while(l<=r) as cond for binary search
// use r=m+1 for else case to push r over l to break while loop
// then return l to get correct index
// use int m = l+(r-l)/2 to prevent overflow
// added additional check of m==nums.size()-1, break because we access [m+1] and have to ensure that it is a valid index