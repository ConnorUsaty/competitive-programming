class Solution {
private:
    unordered_map<char,string> phone_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(vector<string>& ans, string curr, string digits, int i){
        if(i==(int)digits.size()){
            ans.push_back(curr);
            return;
        }

        for(const char& c : phone_map[digits[i]]){
            curr.push_back(c);
            backtrack(ans, curr, digits, i+1);
            curr.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if((int)digits.size()==0) return ans;
        backtrack(ans, "", digits, 0);
        return ans;
    }
};

// ans is all combinations of something -> BACKTRACKING
// implement backtracking with for loop since more than 2 possible options for each
// if only two options at each point can just do push, backtrack, pop, backtrack instead
// need the phone_map due to some numbers having 4 chars instead of 3
// ensure edge cases are handled such as digits = "";