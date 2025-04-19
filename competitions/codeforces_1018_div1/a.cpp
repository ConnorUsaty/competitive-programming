#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);

    int low=1, high=n;
    for(int i=n-1; i>=0; --i){
        if(s[i]=='>'){
            a[i+1] = high;
            high--;
        }
        else if (s[i] == '<'){
            a[i+1] = low;
            low++;
        }
    }
    a[0] = low;

    for(const int& i : a){
        cout << i << ' ';
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
