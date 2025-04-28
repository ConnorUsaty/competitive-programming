#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if((b-a)<=(c-b) && (a+b+c)%3==0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
