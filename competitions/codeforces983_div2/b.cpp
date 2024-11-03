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
// typedef pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, k;
    cin >> n >> k;

    if (n - n/3 <= k || n/3 >= k) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    ans.push_back(1);
    if (k >= n/2) {
        ans.push_back(ans[0]+(n/3));
        ans.push_back(ans[1]+(n/6));
    }
    else {
        ans.push_back(ans[0]+(n/6)+1);
        ans.push_back(ans[1]+(n/3)+(n/6));
    }

    cout << "3\n";
    for (int a : ans) cout << a << ' ';
    cout << "\n";
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
