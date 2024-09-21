class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(0, nums, subset, ans);
        return ans;
    }

private:
    void dfs(int i, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        if (i >= (int)nums.size()) {
            // base case
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(i+1, nums, subset, ans); // dfs with curr element
        subset.pop_back();
        dfs(i+1, nums, subset, ans); // dfs without curr element
    }
};

// Backtracking / dfs / subsets problem

// Make all helper functions private
// Have to pass arrays/vectors into helper function to keep in scope
// Pass all vectors by reference, i.e. vector<int>& nums
// Use .push_back to "append" to vectors
// Use .pop_back() to remove last element, does NOT return element
// Remember to double check base case and return if triggered, else causes infinite recursion
