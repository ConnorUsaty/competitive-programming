#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int last;
    for(int i=0; i<100; ++i) {
        cin >> last;
    }
    last %= 10;
    if(last == 0) last = 10;
    cout << last << "\n";
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // int test_cases;
    // cin >> test_cases;
    // while (test_cases--) {
    solve();
    // }

    return 0;
}
