class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> cache(s.length() + 1, vector<int>(t.length() + 1, 0)); // n * m array for bottom up DP

        // fill in base cases to build off of
        for (int i = 0; i <= s.length(); ++i) {
            cache[i][t.length()] = 1;
        }
        for (int j = 0; j < t.length(); ++j) {
            cache[s.length()][j] = 0;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = t.length() - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    cache[i][j] = (cache[i + 1][j + 1] + cache[i + 1][j]) % MOD;
                } else {
                    cache[i][j] = cache[i + 1][j];
                }
            }
        }
        return cache[0][0];
    }
};

// Bottom up DP is normally more efficient
// Starting in bottom right corner of dp is easier for a lot of problems
// Remember DP is just recursion with memoization
// Break into sub problems -> Look for base cases -> Figure out how to build off of them
// Subsequence / subset problems should immediately make you think DFS / backtracking -> DP for optimal solution