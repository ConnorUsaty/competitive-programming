#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


// can see wizard if cloak is NOT in between us
// ans = num of arrangements that make a true

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool all_same = true;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        if(i>0 && a[i]!=a[i-1]) all_same = false;
    }
    if(all_same && n&1 && a[0]==n/2+1) {
        cout << "2\n";
        return;
    }

    vector<char> dir(n, '_');
    for(int i=1; i<n; ++i) {
        if(a[i]==a[i-1]) {
            if(dir[i-1]=='l'){
                dir[i] = 'r';
            }else if(dir[i-1]=='r'){
                dir[i] = 'l';
            } else {
                dir[i] = 'o';
                dir[i-1] = 'o';
            }
        }
        else if(a[i]==a[i-1]-1){
            dir[i] = 'r';
            if(dir[i-1]=='l') {
                cout << "0\n";
                return;
            }
            dir[i-1] = 'r';
            int j = i-2;
            char c = 'l';
            while(j>=0 && dir[j]=='o') {
                dir[j] = c;
                c = (c=='l' ? 'r' : 'l');
                j--;
            } 
        }
        else if(a[i]==a[i-1]+1){
            dir[i] = 'l';
            if(dir[i-1]=='r') {
                cout << "0\n";
                return;
            }
            dir[i-1] = 'l';
            int j = i-2;
            char c = 'r';
            while(j>=0 && dir[j]=='o') {
                dir[j] = c;
                c = (c=='l' ? 'r' : 'l');
                j--;
            } 
        }
        else {
            cout << "0\n";
            return;
        }
    }

    int r_cnt = 0;
    for(auto c : dir) if(c=='r') r_cnt++;

    int l_cnt = 0;
    for(int i=0; i<n; ++i) {
        if(dir[i]=='r') r_cnt--;

        if(a[i] != 1+l_cnt+r_cnt) {
            cout << "0\n";
            return;
        }

        if(dir[i]=='l') l_cnt++;
    }
    
    cout << "1\n";
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
