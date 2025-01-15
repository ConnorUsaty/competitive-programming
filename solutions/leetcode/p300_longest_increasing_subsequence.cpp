class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> best = {nums[0]};
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>best[best.size()-1]){
                best.push_back(nums[i]);
            }
            else if(nums[i]<best[best.size()-1]){
                int l=0, r=best.size()-1;
                while(l<=r){
                    int m = l+(r-l)/2;
                    if(best[m]<nums[i]){
                        l=m+1;
                    } else {
                        r=m-1;
                    }
                }
                best[l] = nums[i];
            }
        }
        return (int)best.size();
        
        // vector<int> dp(nums.size(), 1);
        // for(int i=1; i<nums.size(); ++i){
        //     for(int j=0; j<i; ++j){
        //         if(nums[j]<nums[i]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
    }
};

// subsequence -> DP
// dp[i] = LIS ending at [i]
// LIS doesnt necessarily end on [n], therefore have to return *max_element()
// O(n^2) time, O(n) space

// Go across only track best subsequence if > last just push_back
// if < find where it should be and update ss -> should replace first num > than curr
// O(nlogn) because we go across once for n, then logn to find where it should go if neccessary