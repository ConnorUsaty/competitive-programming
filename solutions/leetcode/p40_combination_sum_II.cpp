class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& cand, int i, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int j=i; j<(int)cand.size(); ++j){
            if(j>i && cand[j]==cand[j-1]) continue;
            if(target-cand[j]>=0){
                curr.push_back(cand[j]);
                backtrack(ans, curr, cand, j+1, target-cand[j]);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, curr, candidates, 0, target);
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
