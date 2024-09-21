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
    long long n;
    cin>>n; // length of permutation list

    long long p[n+1]={0},b[n+1]={0}; // permutation array and F(i) array
    int us[n+1]={0}; // used array

    // read in permutation array
    for(int i=1;i<=n;i++) {
        cin>>p[i];
    }

    // read in string
    string s;
    cin >> s;

    // start at each possible start point
    for(int i=1; i<=n; i++) {

        if (us[i]) continue; // if weve used this number in a cycle already, we can skip

        int sz=0;

        // while on numbers we haven't used yet
        while(!us[i]) {
            us[i]=1; // mark as used
            sz += s[i - 1] == '0'; // if number black, increment ans
            i=p[i]; // move to next num
        }

        // set black count for all num in cycle
        while(us[i]!=2) {
            b[i]=sz;
            us[i]=2;
            i=p[i];
        }
    }

    // output black counts for all indexes
    for(int i=1; i<=n; i++) {
        cout << b[i] << ' ';
    }

    // go to new line for next test case
    cout << "\n";
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

// 1100 Rating -> Cycle / set / seen problem
// Accepted
// With set constraints can check for occurence / usage of values in O(1) though array i.e. check for 1 at a[1], instead of using map / set
// To check if used / cycle use sets or arrays to check in O(1) depending on constraints
