class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // recursion and swap within input array to get permutations
        // no need to build up / down a subset array as we are simply getting permutations
        // not subsequences or subarrays
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }

private:
    void helper(int i, vector<int>& nums, vector<vector<int>>& ans) {
        if (i >= (int)nums.size()) {
            // base case
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < (int)nums.size(); ++j) {
            // swap and recur to get all permutations
            swap(nums[i], nums[j]);
            helper(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
};

// Recursion / backtracking problem

// When problem is for permutations we can simply swap elements instead of using push_back and pop_back
// For permutations we do not need to build up / build down subsets or subsequences and therefore do not need the above functions or a subset vector
// Simply swap elements around within the input vector and recur until base cases reached

// can use swap(a,b) to swap 2 elements in c++ without a temp variable