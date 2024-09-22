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
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> s;

    int l = 0;
    int r = n-1;
    int m = 0;
    ll ans = 0;

    while (l < r) {
        if (s[l] == 'L' && s[r] == 'R') {
            m++;
            ans +=  1ll * a[l]*m + 1ll * a[r]*m;
            l++;
            r--;
        } else if (s[l] == 'L') {
            ans += 1ll * a[r]*m;
            r--;
        } else if (s[r] == 'R') {
            ans += 1ll * a[l]*m;
            l++;
        } else {
            ans += 1ll * a[l]*m + 1ll * a[r]*m;
            l++;
            r--;
        }

    }
    if (l == r) ans += 1ll * a[l]*m;

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


// 1200 Rating -> 2 Pointer / greedy problem
// Accepted

// Since we want the max sum, we can use a greedy approach and start with 2 pointers on the outside since it is never worse to take the first 'L' 'R' pair that we find
// Use long long for sums and when adding to the sum multiply by 1ll to prevent data loss / overflow