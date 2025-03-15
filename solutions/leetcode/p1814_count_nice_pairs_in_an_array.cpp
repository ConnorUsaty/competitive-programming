class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9+7;
        unordered_map<int,int> diff_cnt; // key = diff, val = count
        int ans = 0;
        for(int i=0; i<(int)nums.size(); ++i){
            int t = nums[i];
            int rev = 0;
            while(t){
                rev *= 10;
                rev += t % 10;
                t /= 10;
            }
            int diff = nums[i] - rev;
            ans  = (ans + diff_cnt[diff]) % MOD;
            diff_cnt[diff]++;
        }
        return ans % MOD;
    }
};

// if abs(nums[i] - rev(nums[i])) == abs(nums[j] - rev(nums[j]))
// nice pair
// therefore for each idx calculate reverse, then calc diff, then store count of diff in map