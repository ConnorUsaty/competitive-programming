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
    int q;
    cin>>q;

    while(q--){
        string s, t;
        cin>>s>>t;

        int i=0, ans=0;
        while(i<s.length() && i<t.length() && s[i]==t[i]){
            ans++;
            i++;
        }
        ans += (i>0)?1:0;
        ans += s.length()-i;
        ans += t.length()-i;
        cout << ans << "\n";
    }

    return;
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    solve();

    return 0;
}

// Not rated yet -> String / greedy problem
// AC

// It is always the best to copy the longest prefix therefore greedy works
// Not every problem has test cases variable input double check before submitting