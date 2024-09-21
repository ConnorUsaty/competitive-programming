class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(0, target, candidates, subset, ans);
        return ans;
    }

private:
    void dfs(int i, int target, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        if (i >= (int)nums.size() || target < 0) {
            // base case
            return;
        }
        if (target == 0) {
            // valid subset
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i, target-nums[i], nums, subset, ans);
        subset.pop_back();
        dfs(i+1, target, nums, subset, ans);
    }
};

// Backtracking / recursion / subsets problem

// Think about cases where you wouldn't want to / don't need to search further, these are your base cases
// Remember to return on all base cases / solution found, or else duplicates / infinite recursion
// Subsets can be found easily with recursion / backtracking
// Just add element, dfs, remove element, dfs again, this covers all scenarios
// Then add proper base cases at top that match problem constraints / goal and add valid subsets to ans
