class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long ans=0;
        long long curr=0;
        for(int i=0;i<k;++i) ans+= nums[i];
        curr = ans;

        for(int i=1;i<nums.size()-k+1;++i){
            curr += nums[i+k-1]-nums[i-1];
            ans = max(ans, curr);
        }

        return double(ans / (1.0*k));
    }
};

// need two variables -> one to keep track of ans (the curr max seen)
// and one to keep track of the current window sum
// the window with the maximum sum will also have the max average
// this info is useful because we can just perform the division once at the end instead of at every single index during the loop