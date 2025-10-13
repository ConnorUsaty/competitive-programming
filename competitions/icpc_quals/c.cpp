#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> seen(51, 0);

    int ans = 0;
    for(int i=0; i<n; ++i) {
        int t;
        cin >> t;
        if(!seen[t]) {
            ans++;
            seen[t] = 1;
        }
    }
    cout << min(ans, k);
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
