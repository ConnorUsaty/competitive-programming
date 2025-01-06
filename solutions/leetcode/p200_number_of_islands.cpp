class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j ){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1'){
            return;
        }
        grid[i][j] = '#';

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;

        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j]=='1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1'){
            return;
        }

        grid[i][j] = '#';

        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// traverse grid, performing dfs at each 1 found to mark island as visited and increment ans