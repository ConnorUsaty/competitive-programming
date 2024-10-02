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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        ll k;
        cin >> k;
        int segs = 0;
        ll ans = 0;

        for (int j = 0; j < 2; ++j) {
            segs -= 1;
            segs += n-j;
            if (segs == k) {
                ans += a[j+1] - a[j];
            }
        }
        for (int j = 2; j < n-1; ++j) {
            segs -= j;
            segs += n-j;
            if (segs == k) {
                ans += a[j+1] - a[j];
            }
        }
        segs = n-1;
        if (segs == k) {
            ans++;
        }
        
        cout << ans << ' ';
    }

    cout << "\n";
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
