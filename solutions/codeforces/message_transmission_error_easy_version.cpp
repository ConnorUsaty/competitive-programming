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
    string t, s;
    cin >> t;

    for (int i = 1; i < (int)t.length(); ++i) {
        int p = 0;
        s = "";
        while (i+p < (int)t.length() && t[0+p] == t[i+p]) {
            s.push_back(t[i+(p++)]);
        }
        if (i+p >= (int)t.length()) break;
    }

    if ((int)s.length() > (int)t.length()/2) {
        cout << "YES\n" << s << "\n";
    } else {
        cout << "NO\n";
    }

    return;
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}

// 1400 Rating -> Strings problem

// To make sure string was not just string repeated and an actual error had to ensure s.length strictly greater than t.length/2
// Checked to see why loop broke outside of rather than checking interally everytime
