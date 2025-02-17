#include <bits/stdc++.h> 

typedef long long ll;
typedef std::pair<int,int> pii;

using namespace std; 


void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n+1);
    for(int i=0; i<n; ++i){
        cin >> a[i+1];
    }
    vector<ll> left(a.begin()+1, a.begin()+r+1);
    vector<ll> right(a.begin()+l, a.end());
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    ll m = r-l+1;
    ll l_ans = accumulate(left.begin(), left.begin()+m, 0*1LL);
    ll r_ans = accumulate(right.begin(), right.begin()+m, 0*1LL);
    cout << min(l_ans, r_ans) << "\n";
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

// can slice a vector through init of another one -> vector<T> v(a.begin(), a.begin()+2); end is non-inclusive
// can accumulate with return type of ll by passing 0*1LL as init value
// can solve problem by solving both options (left or right) independently and taking the best of the two options -> similar to House Robber II
