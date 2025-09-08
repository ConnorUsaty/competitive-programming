class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1==word2) {
            return 0;
        }
        if(word1.size() > word2.size()) swap(word1, word2);
        if(word1.size()==0) return word2.size();

        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        for(int i=0; i<=word1.size(); ++i) {
            dp[i][0] = i;
        }
        for(int i=0; i<=word2.size(); ++i) {
            dp[0][i] = i;
        }
        for(int i=1; i<=word1.size(); ++i) {
            for(int j=1; j<=word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int remove_op = dp[i-1][j];
                    int add_op = dp[i][j-1];
                    int swap_op = dp[i-1][j-1];
                    dp[i][j] = min({remove_op, add_op, swap_op}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

// classic dp -> can either insert, delete, or swap
// build up states and find how to get to current state with best operation