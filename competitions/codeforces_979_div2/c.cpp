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
    cin >> n;
    string s;
    cin >> s;

    if (s[0]=='1' || s[n-1]=='1'){
        cout << "YES\n";
        return;
    }

    for(int i=1;i<n;++i){
        if(s[i-1]=='1' && s[i]=='1'){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
