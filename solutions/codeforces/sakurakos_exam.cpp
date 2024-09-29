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
    // odd number of ones -> impossible regardless of twos
    // even number of ones -> possible if even number of twos or if ones can canel out one two, therefore making them even
    // odd number of twos -> possible iff even ones and can cancel out one two -> Same as case 2 in above line

    int a, b;
    cin>>a>>b;

    // odd num of ones
    if (a%2) {
        cout<<"NO\n";
    }
    // even num of ones and twos -> can cancel themselves out
    else if (!(b%2)) {
        cout<<"YES\n";
    }
    // even num of ones >= 2 and odd num of twos
    else if (a>=2) {
        cout<<"YES\n";
    }
    // else impossible
    else {
        cout<<"NO\n";
    }

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

// 800 Rating -> Parity / sum problem
// Accepted

// Be careful for edge cases i.e. at least 2 1's is >= 2 not > 2
// Did a good job of breaking this solution down into subcases and proving to myself that it would work before implementing
// Continue to identify the problem and break it down and focus on solving and proving before implementation
