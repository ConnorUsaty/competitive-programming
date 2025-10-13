#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 

// EVERYTHING IN INPUT IS 1-INDEXED
// output grids of closest and second closest towers
// if tie -> use tower with lower number
// multi source bfs from all towers
// keep grid of cloest and second closest
// pair<int,int> = {dist, tower num}
// queue = {i, j, tower num}

using tiii = tuple<int,int,int>;

void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<pii>> closest(r, vector<pii>(c, {INT_MAX, -1}));
    vector<vector<pii>> second_closest(r, vector<pii>(c, {INT_MAX, -1}));

    queue<tiii> q;
    for(int i=1; i<=n; ++i) {
        int x, y;
        cin >> x >> y;
        q.push({x-1, y-1, i});
    }

    const vector<pii> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int dist = 0;
    while(!q.empty()) {
        int s = q.size();
        for(int i=0; i<s; ++i) {
            auto [row, col, tower] = q.front();
            q.pop();

            if (dist < closest[row][col].first || (dist==closest[row][col].first && tower < closest[row][col].second)) {
                second_closest[row][col] = closest[row][col];
                closest[row][col] = {dist, tower};

                for(auto& [dr, dc] : directions) {
                    int nr = row + dr;
                    int nc = col + dc;
                    if(nr>=0 && nr<r && nc>=0 && nc<c && closest[nr][nc].second!=tower && second_closest[nr][nc].first==INT_MAX) {
                        q.push({nr, nc, tower});
                    }
                }
            }
            else if (closest[row][col].second != tower && dist < second_closest[row][col].first || (dist==second_closest[row][col].first && tower < second_closest[row][col].second)) {
                second_closest[row][col] = {dist, tower};

                for(auto& [dr, dc] : directions) {
                    int nr = row + dr;
                    int nc = col + dc;
                    if(nr>=0 && nr<r && nc>=0 && nc<c && closest[nr][nc].second!=tower && second_closest[nr][nc].first==INT_MAX) {
                        q.push({nr, nc, tower});
                    }
                }
            }
        }
        dist++;
    }

    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            cout << closest[i][j].second << (j==c-1 ? "\n" : " ");
        }
    }
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            cout << second_closest[i][j].second << (j==c-1 ? "\n" : " ");
        }
    }
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
