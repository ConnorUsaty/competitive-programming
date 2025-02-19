#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    vector<int> pairs = {};
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(!((++cnt[a[i]])&1)) pairs.push_back(a[i]);
    }

    if(pairs.size() >= 2){
        cout << pairs[0] << ' ' << pairs[0] << ' ' << pairs[1] << ' ' << pairs[1] << "\n";
        return;
    }
    else if(pairs.size() == 0){
        cout << "-1\n";
        return;
    }

    int seen = 0;
    int prev = -1;
    sort(a.begin(), a.end());
    for(int i=0; i<n; ++i){
        if(a[i]==pairs[0] && ++seen<=2) continue;
        if(prev != -1 && abs(a[i]-prev) < 2*pairs[0]){
            cout << prev << ' ' << a[i] << ' ' << pairs[0] << ' ' << pairs[0] << "\n";
            return;
        }
        else {
            prev = a[i];
        }
    }
    cout << "-1\n";
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
