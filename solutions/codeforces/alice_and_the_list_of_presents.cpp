// #include <bits/stdc++.h> 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
#include <stack>

typedef long long ll;
typedef long double ld;

using namespace std;
const ll MOD = 1e9+7;


ll fastPow(ll a, ll b){
    if(a==0) return b==0;

    ll ans=1;
    while(b){
        if(b&1) ans = (ans*a)%MOD;
        b >>= 1LL;
        a = (a*a)%MOD;
    }
    return ans;
}


void solve() {
    ll n, m;
    cin >> n >> m;

    // get combinations for each kind of present, i.e. if m = 3 then comb of one present = 2^m - 1
    // then by basic priniciple of counting ans is simply (comb of one)^n
    // therefore ans = ((2^m - 1)^n) % MOD

    ll ans = fastPow(fastPow(2, m) - 1, n) % MOD;
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
