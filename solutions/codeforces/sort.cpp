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


void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre1[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre2[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }

    while (q--){
        int l, r;
        cin >> l >> r;

        int dif = 0;

        for (int c = 0; c < 26; c++){
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];

            dif += abs(v1 - v2);
        }
        cout << dif / 2 << "\n";
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

// 1200 Rating -> Sorting / String / Prefix sum problem

// A string will be equal to another string when sorted if the count of all the letters is equal. Can check this with a vector of size 26 (for each letter) and iterating over string
// Make sure to set default values when incrementing, or else you are just incrementing off something random in memory.
// When a problem requires building up a prefix sum array do it at the very beginning, do NOT do it every loop seperately, you will get TLE.
// can get sum from l to r by doing psum(r) - psum(l)
