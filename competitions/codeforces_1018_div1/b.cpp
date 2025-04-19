#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> l(n);
    for(ll i=0; i<n; ++i){
        cin >> l[i];
    }
    vector<ll> r(n);
    for(ll i=0; i<n; ++i){
        cin >> r[i];
    }

    ll sm = 0;
    vector<ll> mn;

    for(ll i=0; i<n; ++i){
        sm += max(l[i],r[i]);
        mn.push_back(min(l[i],r[i]));
    }
    sort(mn.rbegin(), mn.rend());

    for(ll i=0; i<k-1; ++i){
        sm += mn[i];
    }

    cout << sm+1 << "\n";
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
