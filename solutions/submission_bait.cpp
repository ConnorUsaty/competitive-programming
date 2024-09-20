// #include <bits/stdc++.h> 

// g++-std=c++11-O2-Wall test.cpp-o test

#include <bits/stdc++.h>

using namespace std; 

// ios::sync_with_stdio(0); 
// cin.tie(0);


void solve() {
    int n, x;
    cin >> n;
    unordered_map<int,int> m;
    while (n--) {
        cin >> x;
        m[x]++;
    }
    for (auto& it : m) {
        if (it.second % 2 != 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
// Use seperate solve function
// XOR only works to find a single unique element if you know all other values will cancel each other out. EX: 1, 2, 3 all cancel out but they're all unique therefore wrong solution