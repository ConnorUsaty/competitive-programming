class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int i){
        if (i == (int)nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<(int)nums.size(); ++j){
            swap(nums[i], nums[j]);
            backtrack(ans, nums, i+1);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }
};

// Recursion / backtracking problem

// When problem is for permutations we can simply swap elements instead of using push_back and pop_back
// For permutations we do not need to build up / build down subsets or subsequences and therefore do not need the above functions or a subset vector
// Simply swap elements around within the input vector and recur until base cases reached

// can use swap(a,b) to swap 2 elements in c++ without a temp variable