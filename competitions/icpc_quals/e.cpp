#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 


int get_dist(int x, int y) {
    return (144-x)*(144-x) + (84-y)*(84-y);
}

void solve() {
    int score_red=0, score_yellow=0;

    for(int round=0; round<10; ++round) {
        int n;
        cin >> n;
        vector<int> red_dist(n);
        for(int i=0; i<n; ++i) {
            int x, y;
            cin >> x >> y;
            red_dist[i] = get_dist(x, y);
        }
        sort(red_dist.begin(), red_dist.end());

        int m;
        cin >> m;
        vector<int> yellow_dist(m);
        for(int i=0; i<m; ++i) {
            int x, y;
            cin >> x >> y;
            yellow_dist[i] = get_dist(x, y);
        }
        sort(yellow_dist.begin(), yellow_dist.end());

        if(n==0) {
            score_yellow += m;
            continue;
        }
        if(m==0) {
            score_red += n;
            continue;
        }

        if (red_dist[0] < yellow_dist[0]) {
            int r = 1;
            while(r<n && red_dist[r]<yellow_dist[0]) r++;
            score_red += r;
        } else {
            int y = 1;
            while(y<m && yellow_dist[y]<red_dist[0]) y++;
            score_yellow += y;
        }
    }

    cout << score_red << ' ' << score_yellow << "\n";
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
