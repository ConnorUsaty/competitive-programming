class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9+7;

        vector<int> cnt(26, 0);
        for(const char& c : s) cnt[c-'a']++;

        for(int i=0; i<t; ++i){
            vector<int> next(26, 0);
            next[0] = cnt[25];
            next[1] = (next[0]+cnt[0]) % MOD;
            for(int j=2; j<26; ++j){
                next[j]=cnt[j-1];
            }
            cnt = std::move(next);
        }
        
        long long ans=0;
        for(int i=0; i<26; ++i){
            ans = (ans + cnt[i]) % MOD;
        }

        return static_cast<int>(ans % MOD);
    }
};


// O(n*t) would be TLE, if we went through all t transformations for all n chars
// but we can change to O(n+t*26) = O(max(n,t)) for AC, by getting the cnts of all chars and processing each letter at once