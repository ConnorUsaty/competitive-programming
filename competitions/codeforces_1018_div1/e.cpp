#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans=0;
    ll b = (s[0]=='B')?1:0;
    bool cont = false;
    for(int i=1; i<n; ++i){
        if(s[i]=='B'){
            if(!cont && (i-b)&1 && i<n-1 && s[i+1]=='B'){
                cont = true;
                continue;
            }

            if(cont){
                ans += ((i-b)/2 + 1);
                b += 2;
                cont = false;
            }
            else {
                ans += ((i-b)/2 + (i-b)%2);
                b++;
            }
        }
    }

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
