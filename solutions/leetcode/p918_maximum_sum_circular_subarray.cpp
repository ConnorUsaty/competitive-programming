class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=(int)nums.size();

        vector<int> f(n);
        int ans=INT_MIN, curr=0, first=0, first_mx=INT_MIN;
        for(int i=0; i<n; ++i){
            first += nums[i];
            first_mx = max(first_mx, first);
            f[i] = first_mx;
            curr += nums[i];
            ans = max(ans, curr);
            curr = max(0, curr);
        }
        int last=0, last_mx=INT_MIN;
        for(int i=n-1; i>0; --i){
            last += nums[i];
            last_mx = max(last_mx, last);
            ans = max(ans, last_mx+f[i-1]);
        }
        return ans;
    }
};

// without circular we could just use kadanes to find maximum subarray
// with circular we also have the option to connect the front and the back
// therefore return the max of kadanes and max from front + max from back for any given index