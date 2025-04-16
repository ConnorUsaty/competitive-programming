class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& cand, int i, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(; i<(int)cand.size(); ++i){
            if(target-cand[i]>=0){
                curr.push_back(cand[i]);
                backtrack(ans, curr, cand, i, target-cand[i]);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, candidates, 0, target);
        return ans;
    }
};

// Backtracking / recursion / subsets problem

// Think about cases where you wouldn't want to / don't need to search further, these are your base cases
// Remember to return on all base cases / solution found, or else duplicates / infinite recursion
// Subsets can be found easily with recursion / backtracking
// Just add element, dfs, remove element, dfs again, this covers all scenarios
// Then add proper base cases at top that match problem constraints / goal and add valid subsets to ans
