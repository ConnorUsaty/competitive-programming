#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<ll> b(2*n);
    for(int i=0; i<2*n; ++i){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    vector<ll> ans(2*n);
    ll sm = 0;
    for(int i=0; i<n+1; ++i){
        ans[2*i] = b[i];
        sm += b[i];
    }
    for(int i=1; i<n; ++i){
        ans[2*i+1] = b[n+i];
        sm -= b[i];
    }

    for(int i=0; i<2*n; ++i){
        
    }
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
