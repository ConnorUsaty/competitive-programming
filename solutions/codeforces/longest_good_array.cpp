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
    ll a,b;
    cin >> a >> b;
    // get range of possible increase
    b-=a;

    // binary search to find lowest m such that the increase + l <= r
    ll l=1,r=1000000000;
    while(l<=r) {
        ll m=(l+r)/2;

        if(m*(m-1)/2>b) {
            r=m-1;
        }
        else {
            l=m+1;
        }
    }
    cout<<l-1<<"\n";
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

// 800 Rating -> Math / binary search
// Accepted

// When explicit bounds are set on the answer and it is continuous, then binary search can often be used.
// Another key that binary search may be useful besides the above is when we need the biggest x such that still less than y with explicit bounds or bigger than x elements or sorted array
// Work to simplify problems into eqn's where applicable as we did here with (m*(m-1))/2, without this eqn we could not have performed binary search
