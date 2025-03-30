#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());
    cout << mx-mn << "\n";
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
