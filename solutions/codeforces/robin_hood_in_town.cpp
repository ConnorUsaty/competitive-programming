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
    
    // create vector and sum
    ll sum = 0;
    vector<ll> v(n);
    for (auto &c : v) cin >> c, sum += c;

    // impossible if 1 or 2 citizens
    if (n < 3) {
        cout << "-1\n";
        return;
    }
 
    // sort to easily find middle element (could also use quick select)
    sort(v.begin(),v.end());

    // solve equation to find x
    cout << max(0LL,v[n/2]*2*n-sum+1) << '\n';
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

// 1100 Rating -> Sorting / binary search / math
// Accepted

// Use an equation to solve when possible
// Use ll to be safe when dealing with larger numbers
// Always think about edge cases -> Try to prove your solution will always work