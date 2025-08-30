class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n = (int)nums.size();

        int last_mn=-1, last_mx=-1, l=0;
        long long ans = 0;
        for(int r=0; r<n; ++r) {
            if(nums[r] < minK || nums[r] > maxK) {
                l=r+1;
                continue;
            }
            
            if(nums[r]==minK) last_mn = r;
            if(nums[r]==maxK) last_mx = r;

            if(last_mx>=l && last_mn>=l) {
                ans++;
                ans += (min(last_mn, last_mx)-l);
            }
        }
        return ans;
    }
};

// we can never include anything < minK or > maxK
// NEED to have an element thats = minK and an element thats = maxK
// bounded by last_invalid to next_invalid
// if we have minK and maxK keep expanding and ans+= min(cnt[minK], cnt[maxK])