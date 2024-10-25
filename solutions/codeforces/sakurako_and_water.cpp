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
    
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[i][j];
        }
    }

    int ans=0;
    for(int i=0; i<n; ++i){
        int t=i, j=0, mn=1;
        while(t<n && j<n){
            mn = min(mn, a[t++][j++]);
        }
        ans += max(0, -1*mn);
    }

    for(int j=n-1; j>0; --j){
        int t=j, i=0, mn=1;
        while(t<n && i<n){
            mn = min(mn, a[i++][t++]);
        }
        ans += max(0, -1*mn);
    }

    cout << ans << "\n";
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
