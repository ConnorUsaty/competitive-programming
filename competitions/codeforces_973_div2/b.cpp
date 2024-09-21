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
    int n, f=0;
    cin >> n;
    // i < j
    // i is eliminated
    // therefore fighter at [-1] is always the last standing
    // j -= i
    // get second last fighter to fight everyone decreasing their rating as low as possible before fighting the last fighter
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        
        if (i == n-2) {
            f -= x;
        } else {
            f += x;
        }
    }

    cout << f << "\n";
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
