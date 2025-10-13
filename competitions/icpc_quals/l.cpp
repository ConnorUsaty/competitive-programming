#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int first = a[0] / 3;
    int last = a[n-1] / 3;
    int mid = a[1] - (first*2);
    cout << first << ' ' << mid << ' ' << last << "\n";
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
