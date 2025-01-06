#define ll int
#define FOR(i,a,b)      for(ll i=(a);i<(b);i++)

class Solution {
public:
    int makeStringGood(string s) {
        vector<ll> count(26, 0); for (auto c : s) count[c-'a']++;
        ll mx = 0; for (auto x : count) mx = max(x, mx);
        ll res = INT_MAX;
        FOR(target, 1, mx+1) {
            vector<ll> dp(27, 0);
            for (ll j = 25; j >=0; j--) {
                dp[j] = count[j] + dp[j+1]; // delete all 
                dp[j] = min(dp[j], abs(count[j]-target) + dp[j+1]); // insert or remove to have exactly target
                ll moveNext = count[j] > target ? count[j]-target : count[j]; // move next
                if (j+1 < 26 && count[j+1] < target)
                    dp[j] = min(dp[j], moveNext + max(target-count[j+1]-moveNext, 0) + dp[j+2]);                
            }
            res = min(res, dp[0]);
        }
        return res;
    }
};

// bottom up will almost always be more time and space efficient than top down with memo
// however bottom up is normally harder to come up with