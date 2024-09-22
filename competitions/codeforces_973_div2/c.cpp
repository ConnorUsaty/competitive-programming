// g++-std=c++11-O2-Wall test.cpp-o test

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
typedef long long ll;
typedef long double ld;

using namespace std; 


bool ask(string t) {
    // check if t substr of s
    cout << "? " << t << endl;
    int res;
    cin >> res; // 1 if True, 0 if False
    return res;
}
 
void result(string s) {
    // send final result
    cout << "! " << s << endl;
}


void solve() {
    int n;
    cin >> n;
    string cur;

    // build up suffix
    while ((int)cur.size() < n) {
        if (ask(cur + "0")) {
            cur += "0";
        } else if (ask(cur + "1")) {
            cur += "1";
        } else {
            break;
        }
    }

    // build up prefix
    while ((int)cur.size() < n) {
        if (ask("0" + cur)) {
            cur = "0" + cur;
        } else{
            cur = "1" + cur;
        }
    }

    result(cur);
    return;
}


int main() { 
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

