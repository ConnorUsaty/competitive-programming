#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i<m; ++i) {
        cin >> a[i];
        a[i] = min(a[i], (int)n);
    }

    vector<int> first(n+1, 0);
    vector<int> second(n+1, 0);
    for (int i=0; i<m; ++i) {
        first[1]++;
        first[min(a[i], (int)n-1) + 1]--;
        second[max(1, (int)n-a[i])]++;
        second[n]--;
    }
    
    ll ans = 0, cnt1 = 0, cnt2 = 0;
    for (int i=1; i<=n; ++i) {
        cnt1 += first[i];
        cnt2 += second[i];
        ans += cnt1 * cnt2;
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
