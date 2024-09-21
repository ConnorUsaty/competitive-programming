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
    int x, y, k;
    cin >> x >> y >> k;

    cout << int(max(2*((x+k-1)/k)-1, 2*((y+k-1)/k))) << "\n";

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

// 1100 Rating -> Path / Steps problem
// Accepted
// Based on possible moves we know she is bounded by the max of x or y since she cannot do 2 jumps in the same direction one after the other
// (x+k-1)/k = ceil(x/k) ???
// Instead of doing x>y if statements just use max in cout