#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n; 
    cin >> n;
    string a, b; 
    cin >> a >> b;

    int cnt1 = 0, cnt2 = 0;
    for (int i=0; i<n; ++i) {
        if (i&1) {
            cnt2 += (a[i]=='0');
            cnt1 += (b[i]=='0');
        } else {
            cnt1 += (a[i] == '0');
            cnt2 += (b[i] == '0');
        }
    }
    cout << ((cnt1>=(n+1)/2 && cnt2>=n/2) ? "YES\n" : "NO\n");
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
