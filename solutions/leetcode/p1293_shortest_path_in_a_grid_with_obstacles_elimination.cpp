using tiii = tuple<int,int,int>;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = (int)grid.size(), n = (int)grid[0].size();
        const vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        queue<tiii> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        q.push({0, 0, k});
        visited[0][0] = k;

        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; ++i){
                auto [x, y, c] = q.front();
                q.pop();

                if(x==m-1 && y==n-1) return steps;

                for(auto& [dx, dy] : directions){
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        int nc = (grid[nx][ny]==1 ? c-1 : c);
                        if(visited[nx][ny]<nc){
                            visited[nx][ny] = nc;
                            q.push({nx,ny,nc});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// bfs but visited[i][j] = max k value this cell has been visited with
// if we try to revisit a cell with k <= visited[i][j], its worse, dont visit
// if we try to revisit a cell with k > visited[i][j], there is a POSSIBILITY is is better
// therefore visit (push to q) and update visited[i][j] = k