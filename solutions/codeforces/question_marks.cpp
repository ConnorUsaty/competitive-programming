// #include <bits/stdc++.h> 
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

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(5,0);
    for(char c : s){
        if (c=='A') cnt[0]++;
        else if (c=='B') cnt[1]++;
        else if (c=='C') cnt[2]++;
        else if (c=='D') cnt[3]++;
        else if (c=='?') cnt[4]++;
    }

    int ans=4*n-cnt[4];
    for(int i=0;i<4;++i){
        ans -= max(0,cnt[i]-n);
    }

    cout << ans << "\n";
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
