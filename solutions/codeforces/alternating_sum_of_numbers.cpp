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
// typedef pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        if (i%2) {
            // odd
            sum -= temp;
        } else {
            // even
            sum += temp;
        }
    }

    cout << sum <<"\n";
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

// 800 Rating
// Accepted

// Just loop through and check if index if odd or even to subtract or add
// Can use i%2 for odd or !i%2 for even