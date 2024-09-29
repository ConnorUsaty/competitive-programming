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
    // inc any element by a
    // inc any element by b
    // min range of array after x operations -> output the min range
    int n,a,b,mx=0;
    cin>>n>>a>>b;

    // greedily increase curr_min element in array by max(a,b) until > curr_max, then check if min(a,b) gets any closer
    vector<int> c(n);
    for(int i=0;i<n;++i){
        cin>>c[i];
        mx=max(mx,c[i]);
    }

    priority_queue<int,vector<int>,greater<int>> pq(begin(c), end(c)); //minHeap
    while (pq.top()+min(a,b) <= mx){
        int t = pq.top();
        pq.pop();

        if (t+max(a,b) <= mx) {
            t+=max(a,b);
            pq.push(t);
        } else {
            t+=min(a,b);
            pq.push(t);
        }
    }

    cout<<mx-pq.top()<<"\n";
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

// 1500 Rating -> Min value, number theory
// Solution is correct but TLE

// pq never seems to be the solution in cp ?? always TLE ?
