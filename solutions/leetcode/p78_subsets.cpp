class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int i){
        if (i==nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(ans, nums, curr, i+1);
        curr.pop_back();
        backtrack(ans, nums, curr, i+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, nums, curr, 0);
        return ans;
    }
};

// Backtracking / dfs / subsets problem

// Make all helper functions private
// Have to pass arrays/vectors into helper function to keep in scope
// Pass all vectors by reference, i.e. vector<int>& nums
// Use .push_back to "append" to vectors
// Use .pop_back() to remove last element, does NOT return element
// Remember to double check base case and return if triggered, else causes infinite recursion
