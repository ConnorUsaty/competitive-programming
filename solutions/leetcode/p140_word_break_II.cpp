class Solution {
private:
    void backtrack(vector<string>& ans, string& curr, const unordered_set<string>& words, const string& s, int start) {
        if (start == s.length()) {
            ans.push_back(curr);
            return;
        }

        for (int end=start+1; end<=s.length(); ++end) {
            string word = s.substr(start, end-start);

            if (words.find(word) != words.end()) {
                string orig = curr;
                if (!curr.empty()) curr += " ";
                curr += word;
                backtrack(ans, curr, words, s, end);
                curr = orig;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string curr;
        backtrack(ans, curr, words, s, 0);
        return ans;
    }
};

// have to return all combinations of something -> BACKTRACKING
// since we must actually generate and return all combinations time complexity must be at least O(2^n)
// becuase at each of n indexes it is possible for it to split into 2 branches, resulting in 2^n branches
// for each branch O(n) work must be done to process it, therefore O(n*2^n) time regardless of approach for this problem
