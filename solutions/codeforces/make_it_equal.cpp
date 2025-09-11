#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


// need to turn s into t
// can turn any element in s into s[i] + n*k or abs((s[i]%k)-k) + n*k

void solve() {
    ll n, k;
    cin >> n >> k;

    map<ll,ll> cnt;
    for(int i=0; i<n; ++i) {
        ll t;
        cin >> t;
        cnt[t%k]++;
    }

    bool ok = true;
    for(int i=0; i<n; ++i) {
        ll t;
        cin >> t;

        ll key1 = t%k;
        if(cnt[key1] > 0) {
            cnt[key1]--;
        } else {
            ll key2 = abs(key1 - k) % k;
            if(cnt[key2] > 0) {
                cnt[key2]--;
            } else {
                ok = false;
            }
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}
