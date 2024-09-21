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
typedef long long ll;
typedef long double ld;

using namespace std; 


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<>()); // sort in descending order
    int ans = a[0]; // max value

    for (int i = 1; i < n; ++i) {
        if (i%2) {
            // Odd number -> Bob turn
            int inc = min(k, a[i-1]-a[i]);
            a[i] += inc;
            k -= inc;
            ans -= a[i];
        }
        else {
            // Alice turn
            ans += a[i];
        }
    }

    cout << ans << "\n";
    return;
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// 1100 Rating -> Sorting / greedy problem
// Accepted
// Sorting is not always the enemy. Although sorting takes O(nlogn) it can still be the most optimized solution in some problems. Don't always disregard this option.
// sort(a.begin(), a.end(), greater<>()); // sort vector in descending order in c++
