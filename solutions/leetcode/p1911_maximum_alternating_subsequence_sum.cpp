typedef long long ll;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=(int)nums.size();

        ll ans=-1, mn=nums[0];
        for(int i=0; i<n; ++i){
            ll t = ans;
            ans = max(nums[i]*1LL, ans-mn+nums[i]);
            ans = max(ans, t);
            if(ans!=t){
                mn=nums[i];
            }else{
                mn=min(mn,nums[i]*1LL);
            }
        }
        return ans;
    }
};

// came up with O(n^2) dp solution on own -> TLE
// with slight hint from solutions page came up with and implemented greedy O(n) solution
// solution follows similar logic from Best Time to Buy and Sell Stock