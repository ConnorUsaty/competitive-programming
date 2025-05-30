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
    // ans in max - min * n-1
    int n;
    cin>>n;

    int mx = -1;
    int mn = 1001;
    for(int i=0;i<n;++i){
        int t;
        cin>>t;
        mx = max(mx, t);
        mn = min(mn, t);
    }

    cout << (mx-mn)*(n-1) << "\n";
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
