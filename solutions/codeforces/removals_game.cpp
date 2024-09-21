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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (a == b) {
        cout << "Bob\n";
        return;
    }

    reverse(a.begin(), a.end());

    if (a == b) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";
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

// 1000 Rating -> Games question
// Accepted
// For games work out if there is specfici conditions or scenarios where one person wins. Check if they win in only those conditions or if you can find a pattern
// Can reverse an array using reverse(a.start(), a.end()) in C++
