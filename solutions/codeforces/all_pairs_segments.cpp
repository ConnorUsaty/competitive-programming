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
    cin>>n>>q;

    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    map<ll,int> cnt;
    for(int i=0;i<n;++i){
        cnt[(i+1)*(n-(i+1)+1)-1]++;
    }
    for(int i=0;i<n-1;++i){
        cnt[(i+1)*(n-(i+1)+1)-1] += a[i+1]-a[i]-1;
    }

    for(int i=0;i<q;++i){
        int k;
        cin>>k;
        cout<<cnt[k]<<' ';
    }
    cout<<"\n";
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
