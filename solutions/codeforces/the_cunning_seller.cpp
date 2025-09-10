#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 

// 3^0 = 1 -> 3^1 + 0*3^-1 = 3 + 0 = 3
// 3^1 = 3 -> 3^2 + 1*3^0 = 9 + 1(1) = 10
// 3^2 = 9 -> 3^(2+1) + 2*3^(2-1) = 27 + 2(3) = 33
// to make least number of transactions always take biggest power of 3 <= remaining

// go up then go down = O(log3(n))
// maintain a = 3^(x+1) and b = 3^(x-1) separately
// a = m*3, b = x*m/3

void solve() {
    ll n;
    cin >> n;

    ll x = 0;
    ll m = 1;
    while(m <= n/3) {
        m *= 3;
        x++;
    }

    ll ans = 0;
    // now at biggest power of 3 <= n
    while(n) {
        if(m<=n) {
            ans += (m*3) + (x*(m/3));
            n -= m;
        }
        else {
            m /= 3;
            x--;
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
