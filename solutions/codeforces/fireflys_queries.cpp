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
    ll n, q;
    cin >> n >> q;

    // create prefix sum array
    vector<ll> a(n), ps(1);
    for (ll &r : a) {
        cin >> r;
        ps.push_back(ps.back() + r);
    }
    for (ll &r : a) {
        ps.push_back(ps.back() + r);
    }

    // for each query add on x total sums for cycles fully covered, then the suffix sum of the leftmost in query and prefix of rightmost in query
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll i = l / n, j = r / n;
        l %= n; r %= n;
        cout << ps[n] * (j - i + 1) - (ps[i + l] - ps[i]) - (ps[j + n] - ps[j + r + 1]) << "\n";
    }

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

// 1700 Rating -> prefix sum question
// Accepted

// Again it is seen that when we can use prefix sum to calculate the difference between a range or interval or two points summation / count that prefix sum is the best answer
// If it looks like prefix sum but prefix sum doesn't look like it would fit in memory or work, see if there is an equation you can use for each index instead of ps[n
]