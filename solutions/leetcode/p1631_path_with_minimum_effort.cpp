using tiii = tuple<int,int,int>;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        const vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        priority_queue<tiii, vector<tiii>, std::greater<>> pq; // {effort, row, col}
        vector<vector<int>> visited(m, vector<int>(n, -1));
        pq.push({0, 0, 0});

        while(!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();

            if(visited[r][c] != -1) continue;
            if(r==m-1 && c==n-1) return h;
            visited[r][c] = h;

            for(const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==-1) {
                    int nh = max(h, abs(heights[r][c] - heights[nr][nc]));
                    pq.push({nh, nr, nc});
                }
            }
        }
        return -1;
    }
};

// O(m*nlog(m*n)) time, O(m*n) space for visited

// can move up, down, left, right
// find MIN effort
// effort = MAX(abs diff in height between any 2 adj cells)

// djikstras ? explore paths with less effort first

// for any min path problem even if not explicitly a graph with weighted edges, we can greedily try optimal paths with djikstras to arrive at the optimal answer