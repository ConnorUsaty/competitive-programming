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
    string s;
    cin>>s;
    int id=0;

    // go until first '0'
    while(id<n&&s[id]=='1') {
        id++;
    }

    // if all ones only valid case is length of 4
    if(id==n) {
        if(n==4) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }

    else {
        // check if first zero is at proper placement, if yes it has to be from a perfect square
        if((id-1)*(id-1)==n) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
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

// 800 Rating
// Accepted

// Focus on solving problem and breaking down into cases. Don't just try to brute force it without thinking
// Think about constraints / hints given in problem, i.e. for this the string had to be from a beautiful rectangle but may not be a square
