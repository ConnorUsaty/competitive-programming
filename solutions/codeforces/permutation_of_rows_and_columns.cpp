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
    int n,m;
    cin>>n>>m;

    vector<int> a(n, vector<int>(m)); // n rows, m cols
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    vector<int> b(n, vector<int>(m)); // n rows, m cols
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>b[i][j];
        }
    }

    if (a==b||n==1||m==1){
        cout<<"YES\n";
    }

    // if theres a repeat i.e. 2 in col 1 in both a and b then the col has to have the same cnt, else not possible ?

    map<int,int> cnt;
    for (int i=0;i<n;++i){

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
