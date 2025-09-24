class Solution {
public:
    int distinctSubseqII(string s) {
        const int n = s.size();
        const int MOD = 1e9 + 7;

        std::array<int, 26> last;
        std::fill(last.begin(), last.end(), 0);
        std::vector<int> dp(n+2, 0);
        dp[1] = 1;

        for(int i=2; i<=n+1; ++i) {
            int key = s[i-2]-'a';
            dp[i] = ((dp[i-1]*2) % MOD - dp[last[key]]) % MOD;
            last[key] = i-1;
        }
        
        dp[n+1]--;
        return (dp[n+1] > 0 ? dp[n+1] : dp[n+1]+MOD);
    }
};

// can build off all ss giving * 2
// but will repeat the same as last that ended in that char