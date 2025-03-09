class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;

        int j=0, ans=0; // left of window, i = right
        for(int i=0; i<nums.size(); ++i){
            cnt[nums[i]]++;
            while(cnt[nums[i]]>k){
                cnt[nums[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};