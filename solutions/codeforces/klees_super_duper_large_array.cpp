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
    int n, k;
    cin >> n >> k;

    // min of k
    // max of k+n-1
    vector<int> a(n); // from k+ 0 to k+ n-1 psum array
    a[0] = k;
    for (int i = 1; i < n; ++i) {
        a[i] = k+i;
        a[i] += a[i-1];
    }
    // want to MINIMIZE absolute value of sorted list

    int l = 0;
    int r = n-1;
    ll ans = 1ll*a[n-1];

    while (l <= r) {
        int m = (r+l)/2;
        ans = min(ans, 1ll*abs(a[m]-a[r]));

        if (a[m] - a[r] < 0) {
            l = m+1;
        }
        else if (a[m] - a[r] > 0) {
            r = m-1;
        }
        else {
            ans = 0;
            break;
        }
    }

    cout << ans << "\n";
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


// Make sure same datatype is used in comparisons, i.e. min(int,int) or max(ll,ll)