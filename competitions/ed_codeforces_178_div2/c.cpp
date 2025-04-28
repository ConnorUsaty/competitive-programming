#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // "X ... X" whoever is X will always win
    if(n==2 || s[0]==s[n-1]){
        cout << ((s[0]=='A') ? "Alice\n" : "Bob\n");
        return;
    }

    // "... XX" whoever is X will always win
    if(s[n-1]==s[n-2]){
        cout << ((s[n-1]=='A') ? "Alice\n" : "Bob\n");
        return;
    }

    // "X ... XY" -> if bob is X he wins for sure, if alice is X she wins iff bobs only card is the last card, i.e. no Y cards in (...)
    int cnt[2] = {0,0};
    for(const char& c : s) cnt[c-'A']++;
    cout << ((s[0]=='A' && cnt[1]==1) ? "Alice\n" : "Bob\n");
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
