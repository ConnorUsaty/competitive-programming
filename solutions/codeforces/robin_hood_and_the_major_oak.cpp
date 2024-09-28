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
    int n, k, leaves = 0;
    cin >> n >> k;

    cout << (((n+1)*n/2 - (n-k)*(n-k+1)/2)%2?"NO":"YES") << '\n';
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

// 800 Rating -> Math
// Accepted

// Numbers have the same parity as their powers i.e. 3 = odd, 3^2 = 9 = odd
// adding lots of powers together may cause overflow, use ll for larger numbers
// Find equations for large summations instead of using loops
