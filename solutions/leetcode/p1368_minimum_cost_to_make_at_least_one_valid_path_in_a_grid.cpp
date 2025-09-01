using tiii = tuple<int,int,int>;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m = (int)grid.size();
        const int n = (int)grid[0].size();
        const vector<pair<int,int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};

        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;
        priority_queue<tiii, vector<tiii>, std::greater<>> pq; // min heap
        pq.push({0, 0, 0}); // {w, i, j}
        while(!pq.empty()) {
            auto[w, i, j] = pq.top();
            pq.pop();

            if(w > visited[i][j]) continue;
            if(i==m-1 && j==n-1) return w;

            for(int d=1; d<=4; ++d) {
                auto& [di, dj] = directions[d-1];
                int ni = i + di;
                int nj = j + dj;
                int nw = w + (d==grid[i][j] ? 0 : 1);
                if(ni>=0 && ni<m && nj>=0 && nj<n && nw < visited[ni][nj]) {
                    visited[ni][nj] = nw;
                    pq.push({nw, ni, nj});
                }
            }
        }
        return -1;
    }
};


// djikstras ?
// process lowest cost paths first
// at each [i][j] add all adj cells and mark as visited in x cost

// modified djikstras
// weight is cost of path rather than length

