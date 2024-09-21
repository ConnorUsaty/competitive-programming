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
    int n, k, leaves = 0;
    cin >> n >> k;

    while(k--) {
        leaves += int(pow(n, n));
        n--;
    }

    cout << ((leaves%2==0)?"YES\n":"NO\n");
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
