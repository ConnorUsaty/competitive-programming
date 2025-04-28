#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector<vector<int>> psum(n+1, vector<int>(k,0));
    for(int i=0; i<n; ++i) psum[i+1][s[i]-'a']++;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<k; ++j){
            psum[i][j] += psum[i-1][j];
        }
    }

    vector<int> mn(n,INT_MAX);
    for(int i=0; i<n; ++i){
        for(int j=0; j<k; ++j){
            mn[i] = min(mn[i], psum[i][j]);
        }
    }

    for(int i=0; i<q; ++i){
        string t;
        cin >> t;
        int m=(int)t.length();

        int last_match=-1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        bool ok = false;
        for(int si=n-1; si>=0 && !ok; --si){
            for(int ti=m-1; ti>=0; --ti){
                if(s[si]==t[ti]){
                    dp[si][ti] = 1 + dp[si+1][ti+1];
                    if(dp[si][ti]==m){
                        last_match = si;
                        dp[0][0] = m;
                        ok = true;
                        break;
                    }
                }else{
                    dp[si][ti] = max(dp[si+1][ti], dp[si][ti+1]);
                }
            }
        }

        if(dp[0][0]==m){
            cout << (mn[last_match]+1) << "\n";
        }else{
            cout << "0\n";
        }
    }
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    solve();

    return 0;
}
