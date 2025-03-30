#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<ll> even;
    vector<ll> odd;
    for(int i=0; i<n; ++i){
        ll t;
        cin >> t;
        if(t&1){
            odd.push_back(t);
        } else {
            even.push_back(t);
        }
    }

    if((int)even.size()==0){
        ll ans = *max_element(odd.begin(), odd.end());
        cout << ans << "\n";
        return;
    }
    if((int)odd.size()==0){
        ll ans = *max_element(even.begin(), even.end());
        cout << ans << "\n";
        return;
    }

    ll ans = odd[0];
    for(int i=0; i<max((int)odd.size(), (int)even.size()); ++i){
        if(i<(int)even.size()){
            ans += even[i];
        }
        if(i+1<(int)odd.size()){
            ans += odd[i+1]-1;
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
