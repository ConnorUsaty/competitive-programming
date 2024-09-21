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
    string s, t;
    cin >> s >> t;
    int ti = 0; // idx ptr for t
    int tn = (int)t.length();

    // change each ? in s to lowercase english letter so that t becomes a subsequence (not necessarily continuous) in s
    // just greedy it -> go across s moving checking for next c in t that hasn't been found and switch any ? to that
    for (int si = 0; si < (int)s.length(); ++si) {
        if (ti < tn && s[si] == t[ti]) {
            ti++;
        }
        else if (s[si] == '?') {
            if (ti < tn) {
                s[si] = (t[ti++]); // add t[ti] to ans string and increment ti
            } else {
                s[si] = ('a');
            }
        }
    }

    if (ti<tn) cout << "NO\n";
    else cout << "YES\n" << s << "\n";
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

// 1100 Rating -> Strings / greedy
// Accepted

// In this problem since looking for any output that matches rules we can just use a greedy algorithm as it never makes it worse to move farther into t the first chance we get

// Can increment and add to output in same line -> s[si] = (t[ti++]); // add t[ti] to ans string and increment ti
// string in c++ IS MUTABLE i.e. can do s[i] = '1' and it works. Therefore do not need to build seperate output string
// when using s.length() as loop bound cast as (int) to avoid warnings