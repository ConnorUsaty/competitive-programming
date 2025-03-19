#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, k;
    cin >> n >> k;
    
    if(k&1){
        for(int i=0; i<n-1; ++i){
            cout << n << ' ';
        }
        cout << n-1 << "\n";
    }
    else{
        for(int i=0; i<n-2; ++i){
            cout << n-1 << ' ';
        }
        cout << n << ' ' << n-1 << "\n";
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
