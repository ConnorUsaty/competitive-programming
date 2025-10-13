#include <bits/stdc++.h> 

using ll = long long;
using pii = std::pair<int,int>;

using namespace std; 

// turn left and go
// else if go forward
// else go right

void solve() {
    int r, c;
    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    x--; y--; // 0 index
    int end_x, end_y;
    cin >> end_x >> end_y;
    end_x--; end_y--; // 0 index

    vector<vector<int>> obstacles(r, vector<int>(c, 0));
    for(int i=0; i<r; ++i) {
        std::string t;
        cin >> t;
        for(int j=0; j<c; ++j) {
            char c = t[j];
            if(c == '1') {
                obstacles[i][j] = 1;
            }
        }
    }

    // right, up, left, down
    const vector<pii> directions = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

    // queue<pii> q;
    // q.push({x, y});
    // while(!q.empty()) {
    //     auto [row, col] = q.front();
    //     q.pop();
        
    //     if(row == end_x && col == end_y) {
    //         cout << "1\n";
    //         return;
    //     }
        
    //     for(auto& [dr, dc] : directions) {
    //         int nr = row + dr;
    //         int nc = col + dc;
    //         if(nr>=0 && nr<r && nc>=0 && nc<c && !obstacles[nr][nc]) {
    //             obstacles[nr][nc] = 1;
    //             q.push({nr, nc});
    //         }
    //     }
    // }

    // cout << "0\n";


    vector<vector<vector<int>>> visited(r, vector<vector<int>>(c, vector<int>(4, 0)));
    
    using tiii = tuple<int,int,int>; // {x, y, dir}
    queue<tiii> q;
    q.push({x, y, 0});
    visited[x][y][0] = 1;

    while(!q.empty()) {
        auto [row, col, dir] = q.front();
        q.pop();

        if(row == end_x && col == end_y) {
            cout << "1\n";
            return;
        }

        // turn left and go
        int nd = (dir + 1 >= 4 ? 0 : dir + 1); // turn left
        int nr = row + directions[nd].first;
        int nc = col + directions[nd].second;
        if(nr>=0 && nr<r && nc>=0 && nc<c && !obstacles[nr][nc]) {
            if(!visited[nr][nc][nd]) {
                visited[nr][nc][nd] = 1;
                q.push({nr, nc, nd});
            }
            continue;
        }
        
        // else if go forward
        nd = dir;
        nr = row + directions[nd].first;
        nc = col + directions[nd].second;
        if(nr>=0 && nr<r && nc>=0 && nc<c && !obstacles[nr][nc]) {
            if (!visited[nr][nc][nd]) {
                visited[nr][nc][nd] = 1;
                q.push({nr, nc, nd});
            }
            continue;
        }

        // else turn right
        nd = (dir - 1 < 0 ? 3 : dir - 1); // turn right
        nr = row;
        nc = col;
        if(nr>=0 && nr<r && nc>=0 && nc<c && !obstacles[nr][nc] && !visited[nr][nc][nd]) {
            visited[nr][nc][nd] = 1;
            q.push({nr, nc, nd});
            continue;
        }
    }

    cout << "0\n";
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
