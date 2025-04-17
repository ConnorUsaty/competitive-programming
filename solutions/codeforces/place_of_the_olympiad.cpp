#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    auto check = [&](ll mid){
        ll benches = m / (mid+1);
        ll ext = m % (mid+1);
        ll desks = (benches*mid + ext) * n;
        return desks >= k;
    };

    ll l=0, r=m, ans=LLONG_MAX;
    while(l<=r){
        ll mid = l+(r-l)/2;

        if (check(mid)){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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

// if n and m require ll, use ll for all variables that are a result of arithmetic with n and m. Ex: mid in this problem and all vars within check