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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    char last = 'x';

    // rotate around clock, if 2 reds in a row or 2 blues in a row then no intersection
    for (int i = 1; i <= 12; ++i) {

        if (i == a || i == b) {
            if (last == 'x' || last == 'b') {
                last = 'r';
            } else {
                cout << "NO\n";
                return;
            }
        }
        else if (i == c || i == d) {
            if (last == 'x' || last == 'r') {
                last = 'b';
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
// Use visuals and draw out solution to give context for solution
// Be careful with if conditions, don't always jump to else case, utilize else if