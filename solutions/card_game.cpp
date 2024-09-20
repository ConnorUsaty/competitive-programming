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

int f(int a, int b) {
    if (a > b) {return 1;}
    if (a == b){return 0;}
    if (a < b) {return -1;}
}


void solve() {
    int a, b, c, d, ans=0;
    cin >> a >> b >> c >> d;

    if ((f(a,c) + f(b,d)) > 0) {
        ans++;
    }
    if ((f(a,d) + f(b,c)) > 0) {
        ans++;
    }
    if ((f(b,c) + f(a,d)) > 0) {
        ans++;
    }
    if ((f(b,d) + f(a,c)) > 0) {
        ans++;
    }

    cout << ans << "\n";
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

// 1000 rating -> Games question
// Accepted
// For games look at specific scenarios where players win, especially when given a finite amount of turns / situations
