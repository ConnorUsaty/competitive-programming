class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // calc prefix cnt
        int cnt[102] = {0};
        for(const int& n : nums) cnt[n+1]++;
        for(int i=1; i<102; ++i){
            cnt[i] += cnt[i-1];
        }
        // build ans
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); ++i){
            ans[i] = cnt[nums[i]];
        }
        return ans;
    }
};

// O(n) time, O(1) space

// cam use this solution due to 0 <= nums[i] <= 100 constraint
// would either have to expand cnt array to match constraints or change to sorting solution, O(nlogn) time depending on different constraints
// arrays / vectors are used for prefix sums / cnts since we need the previous index, not maps