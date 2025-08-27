class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        const int n = (int)nums.size();
        int l=0, r=n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            int match_idx = -1;
            if(m>0 && nums[m]==nums[m-1]){
                match_idx = m-1;
            }
            else if(m<n-1 && nums[m]==nums[m+1]){
                match_idx = m+1;
            }
            else {
                return nums[m];
            }

            // ensure m is left match, match_idx is right match
            int t = m;
            if(m>match_idx) swap(m, match_idx);

            int elements_to_left = m-l;
            if(elements_to_left & 1){
                r=m-1;
            } else {
                l=match_idx+1;
            }
        }
        return -1;
    }
};

// will always be odd number of elements
// if we guess an idx [i], and check if [i-1] or [i+1] == [i]
// if neither match -> i is the non dup
// if both match split with those as center
// non dup is on the side with an odd num of elements