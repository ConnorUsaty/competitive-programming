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
    int n,r;
    cin>>n>>r;

    int m=0;
    int ans=0;

    for(int i=0;i<n;++i){
        int t;
        cin>>t;
        ans += (t/2)*2;
        r -= t/2;
        m += t%2;
    }

    if(r>m) ans += m;
    else ans += (2*r)-m;

    cout<<ans<<"\n";
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

// Unrated -> Greedy / math
// AC

// Break problem down into cases focus on problem solving and implement after
// Can use greedy since it is ALWAYS better to pair all possible family members together
