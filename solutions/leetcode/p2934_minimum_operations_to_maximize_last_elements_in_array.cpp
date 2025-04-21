class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, vector<int>& dp){
        int n = (int)nums1.size();
        int mx1 = nums1[n-1];
        int mx2 = nums2[n-1];

        for(int i=0; i<n; ++i){
            if(nums1[i]<=mx1 && nums2[i]<=mx2){
                dp[i+1] = dp[i];
            }
            else if(nums1[i]<=mx2 && nums2[i]<=mx1){
                dp[i+1] = dp[i]+1;
            }
            else{
                dp[n] = INT_MAX;
                break;
            }
        }
        return dp[n];
    }

public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        vector<int> dp(n+1, 0); // min to make valid up until [i] with mx1 and mx2

        int opt1 = solve(nums1, nums2, dp);

        // re-solve with last element swapped
        swap(nums1[n-1], nums2[n-1]);
        dp[0] = 1;
        int opt2 = solve(nums1, nums2, dp);

        int ans = min(opt1, opt2);
        return (ans==INT_MAX) ? -1 : ans;
    }
};

// last element of nums1 must be max(nums1)
// last element of nums2 must be max(nums2)
// return min operations -> -1 if impossible

// set last element
// at each i check 
    
// O(n) time, O(1) space
// can be optimized to O(1) space by changing dp array to an int
// since each state ONLY depends on prev state we can just store that singular prev state    