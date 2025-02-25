class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);

        for(int i=0; i<(int)s.size(); ++i){
            for(const string& w : wordDict){
                if(i+1-(int)w.size() < 0) continue; // not a possible solution

                if(i == w.size()-1 || dp[i-w.size()]){
                    if(s.substr(i+1-w.size(), w.size()) == w){
                        dp[i] = true;
                        break; // skip to next i
                    }
                }
            }
        }

        return dp[s.size()-1];
    }
};

// at each [i] the solution is valid if the current word can build upon an existing solution or start a new one (word is entire prefix of s)
// since we build upon previous solutions at each iteration, this is a dynamic programming problem
// for each index, we check if each word can extend or create a solution
// at the end we simply check if any of these solutions were able to build up to s.size()-1, meaning we were able to build s from words in wordDict

// O(n * m * k) time, where n = s.size(), m = wordDict.size(), k = word.size();
// O(n) space, for dp array