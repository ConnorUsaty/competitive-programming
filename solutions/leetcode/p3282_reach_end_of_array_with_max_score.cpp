using ll = long long;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=static_cast<int>(nums.size());

        ll mx_i = 0, ans=0;
        for(ll i=1; i<n; ++i){
            if(nums[i]>nums[mx_i]){
                ans += (i-mx_i)*nums[mx_i];
                mx_i = i;
            }
        }

        ans += (n-1 - mx_i)*nums[mx_i];
        return ans;
    }
};

// keep going until nums[j] > nums[i]
// then take that jump from i -> j and ans += (j-i)*nums[i]
// continue this until at [n-1]