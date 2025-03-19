#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, k;
    cin >> n >> k;

    // k is odd
    // if curr val of n is odd, must subtract an odd num 1 <= x <= k
    // if even must subtract even num 2 <= x <= k

    ll ans = 0;
    if(n&1){
        n -= min(n, k);
        ans++;
    }

    ans += n/(k-1) + (n%(k-1) ? 1 : 0);
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
