class Solution {
private:
    void backtrack(vector<string>& ans, string& curr, int open, int close){
        if(open==0 && close==0){
            ans.push_back(curr);
            return;
        }

        if(open){
            curr.push_back('(');
            backtrack(ans, curr, open-1, close);
            curr.pop_back();
        }

        if(close>open){
            curr.push_back(')');
            backtrack(ans, curr, open, close-1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string curr = "";
        backtrack(ans, curr, n, n);
        return ans;
    }
};

// generating and returning all valid combinations of something -> BACKTRACKING
// O(2^n) time
// O(n) space
