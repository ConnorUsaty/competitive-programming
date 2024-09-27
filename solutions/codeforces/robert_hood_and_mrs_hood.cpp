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
    int n,k,d;
    cin >> n >> d >> k;
 
    // create prefix sums of starting and ending
    vector<int> ss(n+1),es(n+1);

    // initial places
    for (int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        ss[a]++;
        es[b]++;
    }
    
    // prefix sum
    for (int i=0;i<n;i++) ss[i+1] += ss[i];
    for (int i=0;i<n;i++) es[i+1] += es[i];
 
    int most = 0;
    int robert = 0;
    int mrs = 0;
    int least = 1e9;
    for (int i=d;i<=n;i++){
        int cur = ss[i] - es[i-d];
        if (cur > most) most = cur, robert = i-d+1;
        if (cur < least) least = cur, mrs = i-d+1;
    }
 
    cout << robert << ' ' << mrs << "\n";
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

// 1400 Rating -> Prefix sum / Intervals problem
// Accepted

// Prefix sums are very helpful when finding the difference or amount of something at different indexes that do not have a direct formula like sum of arithmetic sequence
// When making the prefix arrays remember that you have to sum up each index i.e. a[i+1] += a[i] after building up the initial array
