// g++-std=c++11-O2-Wall test.cpp-o test

#include <bits/stdc++.h>

using namespace std; 


void solve() {
    int n, count;
    string s;
    cin >> n; // length of string
    cin >> s; // string EX: 10001
    char p = s[0]; // prev char

    if (p=='0') {
        count = -1;
    } else {
        count = 1;
    }

    // count groups of 0s vs individual ones
    for (int i = 1; i < n; ++i) {
        if(s[i]=='1'){
            count++;
        }
        else if (s[i] != p) {
            count--;  // new group of zeros found
        }
        p = s[i];
    }

    cout << ((count>0)?"Yes\n":"No\n");
}


int main() { 
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// 900 Rating
// Accepted
// Be careful with datatypes i.e. checking if i == 1 vs i == '1'
// be careful with input and output specifications i.e. \n or ' ' between output and whether each digit is to be read in seperately or as one big string
