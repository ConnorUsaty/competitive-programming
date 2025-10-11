class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& g, unordered_map<int,int>& islands) {
        const int n = g.size();
        if(i>=0 && i<n && j>=0 && j<n && g[i][j] == 1) {
            g[i][j] = islands.size() + 2;
            
            int left = dfs(i, j-1, g, islands);
            int right = dfs(i, j+1, g, islands);
            int up = dfs(i-1, j, g, islands);
            int down = dfs(i+1, j, g, islands);

            return 1 + left + right + up + down; 
        }
        return 0;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        const int n = (int)grid.size();

        vector<pair<int,int>> zeros;
        unordered_map<int,int> islands;

        int ans = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    int key = islands.size() + 2;
                    islands.insert({key, dfs(i, j, grid, islands)});
                    ans = max(ans, islands[key]);
                } 
                else if (grid[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        const vector<pair<int,int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto& [i, j] : zeros) {
            int res = 1;
            unordered_set<int> used;
            for(auto& [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;
                if(ni>=0 && ni<n && nj>=0 && nj<n && !used.count(grid[ni][nj])) {
                    res += islands[grid[ni][nj]];
                    used.insert(grid[ni][nj]);
                }
            }
            ans = max(ans, res);
        }

        return ans;
    }
};