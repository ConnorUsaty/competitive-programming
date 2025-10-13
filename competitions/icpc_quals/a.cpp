#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void solve() {
    int need_r, need_g, need_b;
    cin >> need_r >> need_g >> need_b;
    int have_r, have_g, have_b;
    cin >> have_r >> have_g >> have_b;
    int r_or_g, g_or_b;
    cin >> r_or_g >> g_or_b;

    need_r = max(0, need_r - have_r);
    need_g = max(0, need_g - have_g);
    need_b = max(0, need_b - have_b);

    // red and blue take priority
    r_or_g -= need_r;
    g_or_b -= need_b;
    if (r_or_g < 0 || g_or_b < 0 || (r_or_g + g_or_b < need_g)) {
        cout << "-1\n";
    } else {
        cout << (need_r + need_g + need_b) << "\n";
    }
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    solve();

    // int test_cases;
    // cin >> test_cases;
    // while (test_cases--) {
    //     solve();
    // }

    return 0;
}
