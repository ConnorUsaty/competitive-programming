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
    ll n, k;
    cin >> n >> k;

    // min of k
    // max of k+n-1
    // n total elements

    ll l = 1ll* 1;
    ll r = 1ll* n;

    while (l <= r) {
        ll m = 1ll* (r+l)/2;
        ll a = 1ll* (m/2) * (k + (k+m-1));
        ll b = 1ll* (n/2) * (k + (k+n-1)) - a;

        if (a-b < 0) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    ll m = 1ll* (r+l)/2;
    ll a1 = 1ll* (m/2) * (k + (k+m-1));
    ll b1 = 1ll* (n/2) * (k + (k+n-1)) - a1;

    m++;
    ll a2 = 1ll* (m/2) * (k + (k+m-1));
    ll b2 = 1ll* (n/2) * (k + (k+n-1)) - a2;

    cout << min((b1-a1), (a2-b2)) << "\n";
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

// Notice that since array is sorted we can utilize binary search on the sums to find the minimum
// Massive array of n size, where n is unbounded. Therefore we got memory exceeded if we try to precompute prefix sums and use them for binary search
// Need to only calculate necessary sums when they're needed, i.e. the 2 sums we are comparing each time while we binary search
// We can do this with the sum of arithmetic sequence formula -> (n/2) * (a1 + an), where a1 is the first term of the sequence and an is the last
