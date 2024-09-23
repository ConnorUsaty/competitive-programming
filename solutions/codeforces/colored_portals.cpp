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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> sp(n, vector<int>(n, INT_MAX)); // store solutions
    map<char,set<int>> adj; // map of indexes of all cities with portal 'B', 'G', 'Y'
    vector<string> s(n); // vector of city colours i.e. city [0] = "BR"


    // create adj list
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < 2; ++j) {
            adj[s[i][j]].insert(i);
        }
    }

    // perfrom djikstras on every starting point
    for (int i = 0; i < n; ++i) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // first = cost, second = orig index, minHeap
        pq.push(make_pair(0, i));
        sp[i][i] = 0;

        while (pq.size() > 0) {
            pair<int,int> u = pq.top();
            if (u.first == INT_MAX) break;

            pq.pop();
            int idx = u.second;

            for (char& c : s[idx]) {
                for (auto& v : adj[c]) {
                    int w = abs(idx - v);
                    if (sp[i][v] > sp[i][idx] + w) {
                        sp[i][v] = sp[i][idx] + w;
                        pq.push(make_pair(sp[i][v], v));
                    }
                }
            }
        }
    }

    // Output shortest path from vertex q1 to q2 for each query q
    for (int i = 0; i < q; ++i) {
        int q1, q2;
        cin >> q1 >> q2;
        cout << ((sp[q1-1][q2-1]<INT_MAX)?sp[q1-1][q2-1]:-1) << "\n";
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

// 1600 Rating -> Shortest path problem
// TLE but still cool solution

// char can be used as hashmap key
// the types of the two potential outputs from the inline if statement have to be the same
// remember to set starting point weight to 0 