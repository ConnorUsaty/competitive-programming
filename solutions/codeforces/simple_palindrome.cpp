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
    cin>>n;

    // all occurences of each char need to be together or else they create subsequences for everything in between them i.e. aeioa -> aea, aia, aoa, aa, etc.
    const string V = "aeiou";
    string ans;
    for(int i=0;i<n;++i){
        ans.push_back(V[i%5]);
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
