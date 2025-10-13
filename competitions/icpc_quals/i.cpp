#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n);
    for(int i=0; i<n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    long double ans = 0.0;
    long double res = 0.0;
    for(int i=0; i<n; ++i) {
        res += s[i];
        ans = max(ans, (res+a[i]) / (1.0*i));
    }
    cout << ans << "\n";
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // int test_cases;
    // cin >> test_cases;
    // while (test_cases--) {
    solve();
    // }

    return 0;
}
