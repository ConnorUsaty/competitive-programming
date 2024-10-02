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
    int n;
    cin >> n;

    int mx = -1;
    int mx_idx = -1;
    
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp > mx) {
            mx = temp;
            mx_idx = i;
        } else if (mx_idx%2 && !(i%2) && temp == mx) {
            mx = temp;
            mx_idx = i;
        }
    }

    if (mx_idx%2 && n%2) {
        mx += ((n+1)/2)-1;
    } else if (n%2) {
        mx += (n/2)+1;
    } else {
        mx += n/2;
    }

    cout << mx << "\n";
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
