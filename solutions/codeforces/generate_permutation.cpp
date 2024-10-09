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

    if (!(n%2)) {
      cout << -1 << '\n';
      return;
    }
    
    vector<int> p(n);
    iota(p.begin(), p.end(), 1); // 1, 2, ..., n
    for(int i = 1; i < n; i += 2) {
        swap(p[i], p[i + 1]);
    }
    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout<<"\n";

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
