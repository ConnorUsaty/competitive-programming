#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int i=0;
    for(; i<n && k>0; ++i, --k){
        if(s[i]=='L'){
            x--;
        }
        else{
            x++;
        }
        if(x==0) break;
    }
    if(i==n || k==0){
        cout << "0\n";
        return;
    }
    k--;

    i=0;
    for(; i<n && k>0; ++i, --k){
        if(s[i]=='L'){
            x--;
        }
        else{
            x++;
        }
        if(x==0) break;
    }
    if(i==n || k==0){
        cout << "1\n";
        return;
    }
    k--;

    ll ans = 2+(k/(i+1));
    cout << ans << "\n";
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
