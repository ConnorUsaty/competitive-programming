typedef pair<int,int> pii;
const vector<pii> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

class Solution {
private:
    bool valid(int i, int j, vector<vector<int>>& grid){
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Push all rotten oranges
        queue<pii> Q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    Q.push({i,j});
                }
            }
        }

        // BFS
        int ans = (Q.size()==0) ? 0 : -1;
        while(Q.size()>0){
            int s = Q.size();
            for(int i=0; i<s; ++i){
                pii curr = Q.front();
                Q.pop();
                for(auto d : directions){
                    int nx = curr.first+d.first;
                    int ny = curr.second+d.second;
                    if(valid(nx,ny,grid)){
                        grid[nx][ny] = 2;
                        Q.push({nx,ny});
                    }
                }
            }
            ans++;
        }

        // check if we rotted all oranges
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};

// used strategy learned from last problem where you start BFS from all nodes at same time
// remember to mark node as visited at the same time that you push it to queue
// remember to consider edge cases, such as impossible to rot all oranges or not rotten oranges in grid
// used typedef pair<int,int> pii to save implementation time
// used const vector<pii> directions to save implementation time and clean up code
// Q.front() is the correct function -> Same as deque