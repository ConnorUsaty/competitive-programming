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
    int n,m,q;
    cin>>n>>m>>q;

    // intervals have the same answer as david can run to optimal square and get caught there
    // answer is always the optimal squares distance from closest teacher starting point
    // teacher position array is sorted -> binary search
    vector<int> t(m);
    for(int i=0;i<m;++i){
        cin>>t[i];
    }

    for(int i=0;i<q;++i) {
        int d;
        cin>>d;

        // binary search for where d would be in t
        int l=0,r=2; // max(m) = 2 for easy version
        while(l<=r) {
            int m = (r+l)/2;

            if (t[m] > d) {
                r=m-1;
            } else {
                l=m+1;
            }
        }

        // check if between 2 teachers or on the edge
        if (l==0) {
            cout << t[0];
        } else if (l==m) {
            cout << n-t[m-1];
        } else {
            cout << (t[m-1]=t[0])/2 << "\n";
        }
    }

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
