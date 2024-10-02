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
// typedef pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, k, ans=0;
    cin >> n >> k;

    if (k==1) {
        cout<<n<<"\n";
        return;
    }

    ll l=0, r=30;

    while (l<=r) {
        ll m = (r+l)/2;

        if (powl(k,m)>n) {
            r=m-1;
        } else {
            l=m+1; 
        }
    }

    for (int i=l-1;i>0;--i) {
        ll t = (int)powl(k,i);
        ans += int(n/t);
        n -= int((n/t))*t;
    }

    cout<<ans+n<<"\n";
    return;
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
