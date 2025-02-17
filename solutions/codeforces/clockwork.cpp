#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    bool ok = true;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        if(t <= 2*max(i,n-i-1)){
            ok = false;
            // even though its solvable without reading in all inputs
            // we still need to read in all inputs to not mess up future test cases
        }
    }
    cout << ((ok) ? "YES\n" : "NO\n");
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
