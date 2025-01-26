class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& curr, int target, int i){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i==candidates.size() || target<0) return;

        for(int j=i; j<candidates.size(); ++j){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            curr.push_back(candidates[j]);
            backtrack(ans, candidates, curr, target-candidates[j], j+1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, candidates, curr, target, 0);

        return ans;
    }
};

// combinations should immediately signal backtracking or DP
// combinations / permutations / subsequence problem where we actually have to return the combinations
// since we have to return the combinations and not just number of combinations
// that satisfy a property or similar, we must use backtracking

// since the answer CANNOT contain duplicate combinations we must sort the candidates to be able to skip over duplicates -> similar to how we do in 3Sum problem
// when using the loop we only backtrack once in the loop -> push, backtrack, pop
// when not using a loop we do push, backtrack, pop, backtrack
