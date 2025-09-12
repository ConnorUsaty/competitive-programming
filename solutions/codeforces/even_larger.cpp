#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2, 0);
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i=2; i<=n; i+=2) {
        if(a[i-1] > a[i]) {
            ans += a[i-1] - a[i];
            a[i-1] = a[i];
        }
        if(a[i+1] > a[i]) {
            ans += a[i+1] - a[i];
            a[i+1] = a[i];
        }
        if(a[i-1] + a[i+1] > a[i]) {
            ll diff = (a[i-1] + a[i+1]) - a[i];
            ans += diff;
            a[i+1] -= diff;
        }
    }
    cout << ans << "\n";
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
