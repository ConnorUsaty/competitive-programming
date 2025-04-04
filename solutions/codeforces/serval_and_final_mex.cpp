#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    vector<pii> ans;
    int start = 0, end = n-1;
    if(a[0]==0){
        ans.push_back({1,2});
        end--;
        a[0]=1;
        a[1]=1;
    }
    if(a[n-1]==0){
        ans.push_back({end,end+1});
        end--;
        a[end]=1;
    }

    // only 2 idx left
    if(start+1 == end){
        ans.push_back({1,end+1});
    }
    // 3 idx left
    else if(start+2 == end){
        if(a[start+1] == 0){
            ans.push_back({1,2});
            ans.push_back({1,2});
        }
        else {
            ans.push_back({1,3});
        }
    }
    // 4+ idx's left
    // if no zeros in middle do all
    // if zeros in middle just do middle
    else{
        for(int i=start; i<end; ++i){
            if(a[i]==0){
                ans.push_back({2,end});
                end = 2;
                break;
            }
        }
        ans.push_back({1,end+1});
    }

    cout << (int)ans.size() << "\n";
    for(auto& [l,r] : ans){
        cout << l << ' ' << r << "\n";
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
