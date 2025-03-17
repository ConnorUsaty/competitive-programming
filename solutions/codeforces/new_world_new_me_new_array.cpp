#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    k = abs(k);
    // change 1 to n elements to -p <= x <= p
    // therefore impossible if k < -p*n or k > p*n
    if(k > p*n){
        cout << -1 << "\n";
    }
    else{
        cout << ((k/p)+(k%p ? 1 : 0)) << "\n";
    }
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
