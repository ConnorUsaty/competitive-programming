// g++-std=c++11-O2-Wall test.cpp-o test

#include <bits/stdc++.h>

using namespace std; 

// ios::sync_with_stdio(0); 
// cin.tie(0);


void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int ops = 0;
    while (n > 1) {
        n -= (k-1);
        ops++;
    }
    
    cout << ops << "\n";
    return;
}


int main() { 
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// 900 Rating
// Accepted
// Again be careful with input / output formats
// BE CAREFUL WITH EDGE LOOP CONDITIONS, i.e. >= 1 vs > 1
