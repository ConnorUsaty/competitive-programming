#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll,ll> cnt;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<ll> ranked = a;
    sort(ranked.begin(), ranked.end(), greater<>());
    int r = 0;
    
    ll curr = 0;
    for(int i=n-1; i>=0; --i){
        cout << (curr+ranked[r]) << ' ';
        curr += a[i];
        cnt[a[i]]--;

        if(a[i]==ranked[r] && i!=0){
            r++;
            while(cnt[ranked[r]]==0LL){
                r++;
            }
        }
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
