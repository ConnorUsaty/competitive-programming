// #include <bits/stdc++.h> 

// g++-std=c++11-O2-Wall test.cpp-o test

#include <iostream>

using namespace std; 

// ios::sync_with_stdio(0); 
// cin.tie(0);

int main() { 
    int t;
    cin >> t;

    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        // f >= k
        // g <= m
        // maximize, f, min g
        // permutation has to be of length n
        for (int i = n; i > m; --i) {
            cout << i << ' ';
        }
        for (int i = 1; i <= m; ++i) {
            cout << i << ' ';
        }
    }
}

// 900 rating
// Accepted
// Earlier in the array has more weight
// Therefore all the biggest numbers that contribute to f first and all the biggest numbers that contribute to g last
