class Solution {
private:
    bool check(const string t){
        int l=0, r=(int)t.size()-1;
        while(l<=r && t[l]==t[r]){
            l++;
            r--;
        }
        return l>r;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& curr, string& s, int i){
        if(i==(int)s.size()){
            ans.push_back(curr);
            return;
        }

        string t = "";
        for(int j=i; j<(int)s.size(); ++j){
            t.push_back(s[j]);
            if(check(t)){
                curr.push_back(t);
                backtrack(ans, curr, s, j+1);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(ans, curr, s, 0);
        return ans;
    }
};

// if curr is palindrome, backtrack(), then continue adding from s to curr after
// if curr is not just continue adding
// since we have to generate and return all combinations, must backtrack O(2^n)