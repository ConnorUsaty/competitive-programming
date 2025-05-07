typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int n=(int)isWater.size(), m=(int)isWater[0].size();
        const vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        vector<vector<int>> heights(n, vector<int>(m, -1));
        queue<pii> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(isWater[i][j]){
                    heights[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(const auto& d : directions){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && heights[nx][ny]==-1){
                    heights[nx][ny] = heights[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return heights;
    }
};

// each cell = min(adj)+1
// each water cell = 0

// multisource bfs from all water cells?

// we can easily realize that each cell is bound by how close it is to a water cell, therefore just multisource BFS from all watercells