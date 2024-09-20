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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;

    string s;
    // string loop
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s.length() != n) {
            cout << "NO\n";
            continue;
        }

        int ok = 1;
        map<int,char> h;
        map<char,int> d;
        // letter loop
        for (int j = 0; j < s.length(); ++j) {

            if (h.find(a[j]) == h.end() && d.find(s[j]) == d.end()) {
                h[a[j]] = s[j];
                d[s[j]] = a[j];

            } else if (h[a[j]] != s[j] || d[s[j]] != a[j]) {
                ok = 0;
                break;
            }
        }
        cout <<((ok)?"YES\n":"NO\n");
    }
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

// 1000 Rating
// Accepted
// Use of helper functions can slow down execution when passing variables by value. Just use loop with continue, break, and boolean ok var to determine output
