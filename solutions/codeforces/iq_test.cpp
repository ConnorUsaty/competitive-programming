#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    int evens=0, le=-1, lo=-1;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        if (t&1){
            lo=i+1;
        } else {
            evens++;
            le=i+1;
        }
    }
    cout << (evens>1 ? lo : le) << "\n";
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    solve();

    return 0;
}
