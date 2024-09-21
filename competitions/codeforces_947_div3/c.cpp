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

typedef long long ll;
typedef long double ld;

using namespace std; 


void solve() {
    int n, m, sum = 0;
    cin >> n;

    if (n <= 2) {
        while(n--) {
            int temp;
            cin >> temp;
        }
        cout << -1 << "\n";
        return;
    }

    m = floor(n/2)+1;
    priority_queue<int> pq; // maxHeap -> Store m smallest elements

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sum += temp;

        if (pq.size() < m) {
            pq.push(temp);
        } else if (pq.top() > temp) {
            pq.pop();
            pq.push(temp);
        }
    }
    int x = int(floor((pq.top()*2*n)-sum)+1);

    cout << ((x>0)?x:0) << "\n";
    return;
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
