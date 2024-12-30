class Solution {
private:
    void backtrack(vector<string>& ans, string curr, int i, int n) {
        if(i==n){
            ans.push_back(curr);
            return;
        }

        if(isalpha(curr[i])){
            curr[i] = toupper(curr[i]);
            backtrack(ans, curr, i+1, n);
            curr[i] = tolower(curr[i]);
        }
        backtrack(ans, curr, i+1, n);
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(ans, s, 0, (int)s.length());
        return ans;
    }
};

// subsequences / combinations / permutations should immediately signal backtracking / DP
// when each subsequence / comb / perm needs to be tracked and returned, normally just backtracking
// when a certain trait of the ss / comb / perm needs to be tracked and returned, normally optimizable via DP

// For backtracking:
// Make your base case / return clause
// Make your push / pop (in this case it was changing char from upper to lower)
// backtrack after the push / pop and iterate through object
