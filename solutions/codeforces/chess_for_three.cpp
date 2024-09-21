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
    int x, y, z;
    cin >> x >> y >> z;

    if ((x+y+z) % 2 != 0) {
        // impossible
        cout << -1 << "\n";
        return;
    }

    // possible
    cout << (x + y + z - max(0, z - x - y)) / 2 << "\n";
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

// 900 Rating
// Accepted
// Look for pattersn / math equations to simplify when possible
