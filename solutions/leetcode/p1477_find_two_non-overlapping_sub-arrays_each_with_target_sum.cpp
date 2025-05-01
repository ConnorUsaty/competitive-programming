class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=(int)arr.size();
        vector<int> dp(n, 1e6);
        int ans=1e6, curr=0, j=0;
        for(int i=0; i<n; ++i){
            curr += arr[i];
            while(curr > target){
                curr -= arr[j++];
            }
            if(curr == target){
                int w_size = i-j+1;
                ans = min(ans, w_size+dp[max(0, j-1)]);
                dp[i] = min(dp[max(0, i-1)], w_size);
            }
            else{
                dp[i] = dp[max(0, i-1)];
            }
        }
        return (ans==1e6 ? -1 : ans);
    }
};

// can use sliding window because arr[i] >= 1
// therefore increasing window size always increases window sum
// therefore decreasing window size always decreases window sum

// however windows may overlap, therefore we mark the minimum length window we have found up until i in dp[i]
// ans is the minimum of two windows
// so at each curr window that == target we check if curr window + best window that doesnt overlap is a better ans