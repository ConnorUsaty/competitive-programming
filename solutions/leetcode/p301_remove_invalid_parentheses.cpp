class Solution {
private:
    void backtrack(const string& s, int i, int diff, int l, int r, string& curr, unordered_set<string>& ans) {
        if(i>=s.size()) {
            if(l==0 && r==0 && diff==0) ans.insert(curr);
            return;
        }

        curr.push_back(s[i]);
        if(s[i]=='(') diff++;
        else if(s[i] == ')') diff--;
        if(diff >= 0) backtrack(s, i+1, diff, l, r, curr, ans);

        if(s[i] == '(' && l > 0) {
            curr.pop_back();
            diff--;
            if(diff >= 0) backtrack(s, i+1, diff, l-1, r, curr, ans);
        }
        else if(s[i] == ')' && r > 0) {
            curr.pop_back();
            diff++;
            if(diff >= 0) backtrack(s, i+1, diff, l, r-1, curr, ans);
        }
        else {
            curr.pop_back(); // have to pop for backtracking even if mandatory
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0, right=0;
        for(const char& c : s) {
            if(c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left) {
                    left--;
                } else {
                    right++;
                }
            }
        }

        unordered_set<string> ans;
        string curr;
        backtrack(s, 0, 0, left, right, curr, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};

// O(2^n), at each of n indexes we have 2 options
// O(n) space

// for bracket problems we can keep a left and right cnt
// everytime we encounter a right we MUST have valid lefts for it to match to
// else we have to increment right permanently
// we can use this info to "precompute" minimums which allows us to prune our dfs a bunch and cut down the states significantly
// we ALWAYS have to pop back before the next state to ensure the backtracking works, even if we do not continue a path with the back popped