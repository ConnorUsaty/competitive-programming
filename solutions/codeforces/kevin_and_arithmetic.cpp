#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    bool even = false;
    for(int i=0; i<n; ++i){
        ll t;
        cin >> t;
        if(t&1) ans++;
        else even = true;
    }
    cout << ((even) ? ans+1 : ans-1) << "\n";
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
