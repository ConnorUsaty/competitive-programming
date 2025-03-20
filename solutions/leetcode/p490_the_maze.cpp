class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& finish) {
        int n = (int)maze.size(), m = (int)maze[0].size();
        const vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = 1;

        while(!q.empty()){
            pair<int,int> u = q.front();
            q.pop();
            if(u.first==finish[0] && u.second==finish[1]){
                return true;
            }

            for(const auto& d : directions){
                int nx = u.first;
                int ny = u.second;
                while(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]!=1){
                    nx += d[0];
                    ny += d[1];
                }
                nx -= d[0];
                ny -= d[1];
                if(!visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};

// start from start
// go as far as possible in each dir before hitting wall
// then push that to q if !visited
// continue

// empty = 0
// wall = 1
// ball has to keep rolling same dir until hit wall
// once it hits a wall it can choose a new dir
// m x n maze, start and end coords
// output true if there is a path
// output false if there is no path

// [s, 1, f]
// [0, 1, 0]
// [0, 0, 0]
// can start or finish be a wall?
// can start == finish?
// start and finish in maze?