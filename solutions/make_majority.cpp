// g++-std=c++11-O2-Wall test.cpp-o test

#include <bits/stdc++.h>

using namespace std; 

ios::sync_with_stdio(0); 
cin.tie(0);


void solve() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    --n;
    int count = (p==0)?-1:0;
    // count groups of 0s vs individual ones
    while (n--) {
        int x;
        cin >> x;
        if(x==1){
            count++;
        }
        else if (x != p) {
            // new group of zeros found
            count--;
        }
        p = x;
    }

    return ((count>0)?"Yes\n":"No\n")
}


int main() { 
    int t;
    cin >> t;

    while (t--) {
        cout << solve();
    }

    return 0;
}

// 900 Rating
// No way to submit ??