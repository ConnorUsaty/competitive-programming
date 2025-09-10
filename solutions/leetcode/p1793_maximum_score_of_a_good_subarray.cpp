class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        int l=k, r=k, mn=nums[k], ans=nums[k];
        while(l>0 || r<n-1) {
            int l_v = (l>0 ? nums[l-1] : -1);
            int r_v = (l<n-1 ? nums[r+1] : -1);
            if (l_v > r_v) {
                l--;
                mn = min(mn, nums[l]);
            } else {
                r++;
                mn = min(mn, nums[r]);
            }
            ans = max(ans, mn*(r-l+1));
        }
        return ans;
    }
};

// i <= k <= j

// score = min(subarray) * (j-i+1)
// return MAX score

// therefore we want to max the min and max the size
// start as [k, k]
// expand to l or r by taking the max val
// update ans after each iter
// O(n) time, O(1) space