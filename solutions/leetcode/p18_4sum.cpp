class Solution {
private:
    vector<vector<int>> two_sum(vector<int>& nums, int start, long long target) {
        int end = nums.size()-1;
        int l = start, r = end;
        vector<vector<int>> ans;
        while(l<r) {
            int res = nums[l] + nums[r];
            if(res < target || l>start && nums[l]==nums[l-1]) {
                l++;
            } else if (res > target || r<end && nums[r]==nums[r+1]) {
                r--;
            } else {
                ans.push_back({nums[l++], nums[r--]});
            }
        }
        return ans;
    }

    vector<vector<int>> k_sum(vector<int>& nums, int start, int k, long long target) {
        vector<vector<int>> res;

        if(nums.size()-start < k) return res;
        long long average_value = target / k;
        if (nums[start] > average_value || average_value > nums.back()) return res;
        if(k == 2) return two_sum(nums, start, target);

        for(int i=start; i<nums.size(); ++i) {
            if(i != start && nums[i] == nums[i-1]) continue;

            for(vector<int>& subset : k_sum(nums, i+1, k-1, static_cast<long long>(target) - nums[i])) {
                res.push_back({nums[i]});
                res.back().insert(res.back().end(), subset.begin(), subset.end());
            }
        }
        return res;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        return k_sum(nums, 0, 4, target);
    }
};

// have to be careful about duplicates and about long long

// O(n^3) time, O(1) space (not including output / sorting)