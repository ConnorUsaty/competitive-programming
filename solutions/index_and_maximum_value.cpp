// #include <bits/stdc++.h> 

// g++-std=c++11-O2-Wall test.cpp-o test

#include <iostream>
#include <vector>

using namespace std; 

// ios::sync_with_stdio(0); 
// cin.tie(0);

int main() { 
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int y;
        int x = 0;
        for (int i = 0; i < n; ++i) {
            cin >> y;
            x = max(x,y);
        }

        char c;
        int l, r;
        while (m--) {
            cin >> c >> l >> r;
            if (l <= x&&x <= r) {
                if (c == '+') {
                    x++;
                } else {
                    x--;
                }
            }
            cout << x << ' ';
        }
    }
}

// 900 rating
// Accepted
// Can get max on read in without creating array
