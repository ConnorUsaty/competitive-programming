#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    long long cnt[2];
    memset(cnt,0,sizeof(cnt));
    for(const char& c : s){
        if(c=='-'){
            cnt[0]++;
        } else {
            cnt[1]++;
        }
    }

    ll ans;
    if(cnt[0]&1){
        ans = (cnt[0]/2LL)*((cnt[0]/2LL)+1)*cnt[1];
    } else {
        ans = (cnt[0]/2LL)*(cnt[0]/2LL)*cnt[1];
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
