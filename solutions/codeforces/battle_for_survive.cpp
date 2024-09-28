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

    vector<int> a(n);
    ll sum = 0;
    for(int i=0;i<n;++i) cin>>a[i], sum+=1ll*a[i];

    sum -= 2*a[n-2];

    cout << sum << "\n";
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

// 900 Rating -> Math / array
// Accepted

// Instead of putting a bunch of if statements within loop, try to simplify and do specific operation outside loop
// use ll for large sums
