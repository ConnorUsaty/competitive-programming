// #include <bits/stdc++.h> 
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

    int prev;
    cin >> prev;

    bool ok = true;
    for (int i=1;i<n;++i) {
        int t;
        cin >> t;
        if (abs(prev-t)!=5 && abs(prev-t)!=7) {
            ok = false;
        }
        prev = t;
    }

    cout << (ok?"YES\n":"NO\n");
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

// 800 Rating -> Implementation problem

// Remember to read in all inputs for each test case even if they are not necessary to solve that test case