#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;

    unordered_map<string,int> mp;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        auto it = mp.find(s);
        if(it == mp.end()){
            cout << "OK\n";
            mp[s] = 1;
        }
        else{
            cout << (s+to_string(it->second)) << "\n";
            it->second++;
        }
    }
}


int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    solve();

    return 0;
}
