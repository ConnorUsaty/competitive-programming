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
    int n, k;
    cin >> n >> k;

    vector<int> bsum(k+1, 0);
    for(int i=0;i<k;++i) {
        int b, c;
        cin >> b >> c;
        bsum[b] += c;
    }

    sort(bsum.rbegin(), bsum.rend());

    ll ans=0;
    for (int i=0;i<min(n,k);++i) {
        ans += bsum[i];
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
