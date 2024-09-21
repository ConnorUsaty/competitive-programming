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
typedef long long ll;
typedef long double ld;

using namespace std; 


void solve() {
    int cols; // length of strings / rows
    cin >> cols;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    
    // very outside cols will never produce 3 sections
    // only one possible scenario where it can produce 3 sections, check for this setup in both rows
    for (int i = 1; i < cols-1; ++i) {
        if (s1[i] == '.' && s1[i-1] == '.' && s1[i+1] == '.') {
            if (s2[i-1] == 'x' && s2[i] == '.' && s2[i+1] == 'x') {
                ans++;
            }
        }
        else if (s2[i] == '.' && s2[i-1] == '.' && s2[i+1] == '.') {
            if (s1[i-1] == 'x' && s1[i] == '.' && s1[i+1] == 'x') {
                ans++;
            }
        }
    }

    cout << ans << "\n";
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

// 1100 Rating -> String / logic
//

// s[i] = char = 'c'
// when given specific constraints like this check if there are specific conditions necessary for condition to to true / false