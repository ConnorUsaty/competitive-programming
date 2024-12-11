class Solution {
private:
    void comb(vector<vector<int>>& ans, int i, int n, int k, vector<int>& curr){
        if(k==(int)curr.size()){
            ans.push_back(curr);
            return;
        }

        for(;i<=n;++i){
            curr.push_back(i);
            comb(ans, i+1, n, k, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        comb(ans, 1, n, k, curr);
        return ans;
    }
};

// combinations, permutations, subsequences are all backtracking problems
// can be solved similarly with recursion, just push, call func(), pop, to try all possibilities
// make if statement the base case / check needed to be included in the ans
