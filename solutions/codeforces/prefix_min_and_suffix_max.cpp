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
    string s(n, '0');
    s[0] = '1';
    int mn = a[0];
    for(int i=1; i<n-1; ++i) {
        if(a[i] <= mn) {
            mn = a[i];
            s[i] = '1';
        }
    }
    s[n-1] = '1';
    int mx = a[n-1];
    for(int i=n-2; i>0; --i) {
        if(a[i] >= mx) {
            mx = a[i];
            s[i] = '1';
        }
    }
    cout << s << "\n";
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
