class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=(int)nums.size();

        long long ans = 0, curr = 0;
        int j=0;
        for(int i=0; i<n; ++i){
            curr += nums[i];
            while(j<=i && curr*(i-j+1)>=k){
                curr -= nums[j];
                j++;
            }
            ans += (curr==0 ? 0 : (i-j+1));
        }
        return ans;
    }
};

// we can observe that since nums[i] always > 0, expanding the window will always make the window sum bigger, and thus any subarray of the current window will have a smaller sum
// using this fact at each index we find the maximum possible window size that includes element nums[i] (if there is any)
// then we can conclude this window PLUS all subarrays of this window that include nums[i] are also valid
// therefore we add i-j+1 if curr != 0 at the end of each iteration
