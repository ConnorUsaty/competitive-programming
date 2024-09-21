// g++-std=c++11-O2-Wall test.cpp-o test

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

// ios::sync_with_stdio(0); 
// cin.tie(0);


void solve() {
    vector<int> a(2);
    vector<int> b(2);
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    int start, end, ans=0;
    start = max(a[0],b[0]);
    end = min(a[1],b[1]);
    
    if (start > end) {
        ans = 1;
    } 
    else if (start <= end) {
        ans += end-start;

        if (a[0] < start || b[0] < start) {
            ans++;
        }
        if (a[1] > end || b[1] > end) {
            ans++;
        }
    }

    cout << ans << "\n";
    return;
}


int main() { 
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// 1000 Rating -> Interval problem
// Accepted
// Interval problems are often solved with either sorting or looking for overlap or botj
// Often have to get start or end points with min() or max() of current and prev interval
