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


ll dist(pair<int,int> p1, pair<int,int> p2) {
    return 1ll * (p2.first - p1.first) * (p2.first - p1.first) + 1ll * (p2.second - p1.second) * (p2.second - p1.second);
}


void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    pair<int,int> start;
    cin >> start.first >> start.second;
    pair<int,int> finish;
    cin >> finish.first >> finish.second;
    ll path_dist = dist(start, finish);

    for (int i = 0; i < n; ++i) {
        if (dist(a[i], finish) <= path_dist) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

// 1200 Rating -> Math / geometry ptoblem
// Accepted

// Look for simple solutions i.e. distance from circle center and distance from start comparison

// pair<int,int> uses .first and .second to access variables
// for big calculations just return long long, don't take any chances