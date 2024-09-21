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
    string s;
    cin >> n >> s;

    stack<int> stk; // holds indexes of most recent opening brackets
    stk.push(0); // first index has to be an opening bracket
    int cost = 0;

    // since we want minimum cost we can just go across and put down a closing bracket everytime that n_cls < n_opn -> Same as stack.size() > 0
    for (int i = 1; i < n; ++i) {
        if (s[i] == '(') {
            // update most recent opening bracket index by pushing to top of stack
            stk.push(i);
        } 
        else if (s[i] == '_') {
            if (stk.size() > 0) {
                // close a bracket pair and calculate that pairs contribution to cost
                cost += i-stk.top();
                stk.pop();
            } else {
                // don't have a bracket to close -> add an opening bracket
                stk.push(i);
            }
        }
        else {
            // closing bracket found -> close pair and calculate cost contribution
            cost += i-stk.top();
            stk.pop();
        }
    }

    cout << cost << "\n";
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

// 1100 Rating -> Stack / bracket / greedy problem
// Accepted

// Brackets often indicate it is useful to use a stack
// Since we want min cost i.e. close bracket pairs asap, we can use a greedy algorithm going across the string once and closing pairs the first chance that we get
// Stack helps us to keep track of most recent indexes of opening brackets so that we can get the index value in O(1) for our cost calculations

// stk.top() returns top (most recent element), while stk.pop() removes top (most recent element)
// stk.size() returns stack size in O(1), no need to track size with seperate variable