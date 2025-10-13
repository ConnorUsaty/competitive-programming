#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


void answer(int x, int y) {
    cout << "! " << x << ' ' << y << std::endl;
}

void guess(int x, int y) {
    cout << "? " << x << ' ' << y << std::endl;
}

bool check() {
    int check;
    cin >> check;
    return check;
}

void try_square(int x, int y) {
    guess(x, y-1);
    bool left = check();
    guess(x-1, y);
    bool up = check();
    
    if (left && !up) {
        answer(x, y-1);
        return;
    }
    else if(!left && up) {
        answer(x-1, y);
        return;
    }
    else if(left && up) {
        answer(x-1, y-1);
        return;
    }
    else {
        answer(x, y);
    }
}


void solve() {
    vector<pii> guesses = { {2,2}, {2,4}, {4,2} };

    for(auto& [r, c] : guesses) {
        guess(r,c);
        if (check()) {
            try_square(r, c);
            return;
        }
    }

    try_square(4, 4);
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0);

    // int test_cases;
    // cin >> test_cases;
    // while (test_cases--) {
    solve();
    // }

    return 0;
}
