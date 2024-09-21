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

using namespace std; 

// solve by sorting
// void solve() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end()); // sort in descending by default

//     int p2 = 0, p1 = a[0];
//     int ans = (p1<m)?p1:0;

//     for (int i = 1; i < n; ++i) {
//         if (a[i] == a[i-1]) {
//             p1 += a[i];
//         }
//         else if ((a[i]-a[i-1]) == 1) {
//             p2 = p1;
//             p1 = a[i];
//         }
//         else {
//             p2 = 0;
//             p1 = a[i];
//         }

//         if (p1+p2 < m) ans = max(ans, p1+p2);

//     }

//     ans = max(ans,p1+p2);
//     cout << ans << "\n";
//     return;
// }


// solve by counting
void solve() {
    int n, m;
    cin >> n >> m;
    map<int,int> h;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        h[temp]++;
    }

    int ans = 0;

    for (auto& it : h) {
        int cost = it.first;
        int avail = min(m/cost, it.second);
        int curr = avail*cost;
        ans = max(ans, curr);

        if (h.find(++cost) != h.end()) {
            avail = min((m-curr)/cost, h[cost]);
            curr += avail*cost;
            ans = max(ans,curr);
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

// 1100 Rating -> Counting / sorting problem
//

// Problems involving counting of any kind can normally be optimally solved with hashmaps. Look for that solution as it is O(n), compared to sorting O(nlogn)