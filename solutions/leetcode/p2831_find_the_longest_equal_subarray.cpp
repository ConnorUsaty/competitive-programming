class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        int used_k = 0, l = 0, ans = 0;
        unordered_map<int,int> cnt;
        for(int r=0; r<n; ++r) {
            cnt[nums[r]]++;
            if(nums[r] != nums[l]) used_k++;
            while(used_k > k) {
                cnt[nums[l]]--;
                l++;
                used_k = r-l+1 - cnt[nums[l]];
            }
            ans = max(ans, cnt[nums[l]]);
        }
        // make sure every l is checked as a start pt
        while(l<n-1) {
            cnt[nums[l]]--;
            l++;
            ans = max(ans, cnt[nums[l]]);
        }
        return ans;
    }
};

// should always **consider** sliding window for subarray problems
// for deleting k elements or having at most k elements or something
// we can use a sliding window approach, cnting all elements in the window
// then simply shrink the window if we get an invalid window, until it is valid again
// then update ans once the window is valid

// sliding window
// ans = max(ans, r-l+1 - used_k);
// if used_k < 0 shrink until >= 0
// keep cnt of elements in window to properly inc / dec used_k