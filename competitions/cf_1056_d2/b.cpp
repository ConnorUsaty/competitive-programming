#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


// n x n grid
// arrange arrows in a way s.t. exactly k starting cells lead to escaping the maze

// make a path k long that leads to the exit
// make a cycle with all remaining squares

// this is always possible UNLESS k = n^2 - 1
// because we need 2 free squares to make the cycle


// for k squares put them all as U, can always escape upwards
// then for remaining put all as R except n-1, which will be L to create cycle

void solve() {
    int n, k;
    cin >> n >> k;

    if(n*n - 1 == k) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n-1; ++j) {
            if (k>0) {
                cout << 'U';
                k--;
            } else {
                cout << 'R';
            }
        }
        // last col in each row
        if (k>0) {
            cout << "U\n";
            k--;
        } else if (i<n-1) {
            cout << "D\n";
        } else {
            cout << "L\n";
        }
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
