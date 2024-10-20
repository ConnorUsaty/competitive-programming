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
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    sort(a.begin(), a.end());

    int j=0, ans=0;
    for(int i=0;i<n;++i){
        j = max(i,j);
        while(j+1<n && a[j+1]-a[j]<=1 && a[j+1]-a[i]<k) {
            j+=1;
        }
        ans = max(ans, j-i+1);
    }

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
