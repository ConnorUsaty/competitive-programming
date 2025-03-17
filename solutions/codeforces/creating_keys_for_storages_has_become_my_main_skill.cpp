#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n, 0);

    // if x is even we can never set the 1 bit
    if(!(x&1)){
        a[0] = x;
    }
    else{
        // set as many bits as possible before v doesnt match up with x
        int v = 0;
        for(int i=1; i<min(n, x+1); ++i){
            int t = v|i;
            if((t|x) != x) break;
            a[i] = i;
            v = t;
        }
        if(v != x){
            a[n-1] = x;
        }
    }
    
    for(const int& n : a){
        cout << n << ' ';
    }
    cout << "\n";
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
