#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<m; ++i){
        cin >> b[i];
    }

    a[0] = min(a[0], b[0]-a[0]);
    for(int i=1; i<n; ++i){
        if(a[i]>=a[i-1] && b[0]-a[i]>=a[i-1]){
            a[i] = min(a[i], b[0]-a[i]);
        }
        else if(a[i]>=a[i-1]){
            continue;
        }
        else if(b[0]-a[i]>=a[i-1]){
            a[i] = b[0]-a[i];
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
