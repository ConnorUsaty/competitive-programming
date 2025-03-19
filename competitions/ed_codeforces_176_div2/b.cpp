#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    if(k+1>=n) {
        cout << std::accumulate(a.begin(), a.end(), 0LL) << "\n";
        return;
    }

    ll ans=0;
    if(n==2){
        ans = a[0]+a[1];
    }
    else if(k==1){
        ans = max(*max_element(a.begin()+1, a.end()-1)+max(a[0],a[n-1]), a[0]+a[n-1]);
    }
    else{
        sort(a.begin(), a.end());
        for(int i=n-1; i>=n-k-1; --i){
            ans += a[i];
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
