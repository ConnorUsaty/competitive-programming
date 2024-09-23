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
    int n;
    cin >> n;
    ll ans = 0;

    // create array of points
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // count points at each x val
    map<int,int> b; // key = x, val = count
    for (int i = 0; i < n; ++i) {
        b[a[i].first]++;
    }

    // check each x val for a pair of points
    for (auto& p : b) {
        if (p.second == 2) {
            ans += 1ll*n-2;
        }
    }

    // check each point for specific case
    set<pair<int,int>> check(a.begin(), a.end());
    for (auto& p : check) {
        pair<int,int> p1 = make_pair(p.first-1,p.second^1);
        pair<int,int> p2 = make_pair(p.first+1,p.second^1);
        if(check.find(p1) != check.end() && check.find(p2) != check.end()) {
            ans += 1ll*1;
        }
    }

    cout << ans << "\n";
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

// 1400 Rating -> Math / geometry problem
// Accepted

// Make sure comparisons are between same type i.e. set<pii> cannot compate to (int,int) needs to be pii
// When ans is large sum use ll instead of int to prevent stack overflow
// Make sure to initialize variables, you cannot start incrementing them until you have initially set them to your desired start value