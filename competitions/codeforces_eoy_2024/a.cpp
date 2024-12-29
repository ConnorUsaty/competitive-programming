// #include <bits/stdc++.h> 
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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    for(int i=1;i<n;++i){
        if(min(a[i], a[i-1])*2 > max(a[i], a[i-1])){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
