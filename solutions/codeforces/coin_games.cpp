// g++-std=c++11-O2-Wall test.cpp-o test

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

// ios::sync_with_stdio(0); 
// cin.tie(0);


void solve() {
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (char c : s) {
        if (c=='U'){
            count++;
        }
    }

    cout << ((count%2==1)?"YES\n":"NO\n");
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

// For game / winner / last standing questions focus on parity, odd or even, as that often decides the winner
// Can be calculated most times either with counts and applying % to check odd or even, or with XOR operations in specific occasions
