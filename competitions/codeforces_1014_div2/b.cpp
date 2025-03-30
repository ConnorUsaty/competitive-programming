#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int l=0, r=n-1;
    bool progress = false;
    while(l<=r){
        progress = false;

        if(s1[l]=='1'){
            if(l>0 && s2[l-1]=='0'){
                s1[l]='0';
                s2[l-1]='1';
            }
            else if(l+1<n && s2[l+1]=='0'){
                s1[l]='0';
                s2[l+1]='1';
            }
        }
        if(s1[l]=='0'){
            if(l>0 && s2[l-1]=='0' && l+1<n){
                s2[l+1]='0';
            }
            l++;
            progress = true;
        }

        if(s1[r]=='1'){
            if(r+1<n && s2[r+1]=='0'){
                s1[r]='0';
                s2[r+1]='1';
            }
            else if(r>0 && s2[r-1]=='0'){
                s1[r]='0';
                s2[r-1]='1';
            }      
        }
        if(s1[r]=='0'){
            if(r+1<n && s2[r+1]=='0' && r-1>=0){
                s2[r-1]='0';
            }
            r--;
            progress = true;
        }

        if(!progress){
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
