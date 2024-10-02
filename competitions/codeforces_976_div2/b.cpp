#include <bits/stdc++.h> 
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
    ll k, cnt=0, ans=1;
    cin >> k;

    for (ll i=2;cnt<k;++i) {
        int inc = 1;
        for (ll j=2;j*j<=i;++j) {
            if (!(i%j)) {
                inc^=inc;
            }
        }
        cnt += inc;
        ans = i;
    }
    
    cout<<ans<<"\n";
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
