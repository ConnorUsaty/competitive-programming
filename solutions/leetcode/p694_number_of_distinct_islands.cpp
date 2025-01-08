class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, string& island, char dir){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1){
            return;
        }

        grid[i][j] = -1;
        island += dir;

        dfs(i, j+1, grid, island, 'r');
        dfs(i+1, j, grid, island, 'd');
        dfs(i, j-1, grid, island, 'l');
        dfs(i-1, j, grid, island, 'u');

        island += 's';
    }

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> seen;
        int islands=0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==1){
                    string island = "";
                    dfs(i, j, grid, island, 's');
                    if(seen.find(island)==seen.end()){
                        islands++;
                        seen.insert(island);
                    }
                }
            }
        }
        return islands;
    }
};

// similar to number of islands where we have to dfs each island and mark it as visited / as one island
// however we have to keep track of the shapes of ihe visited islands which can be done through a hash
// the easiest hash to use for translational only is the path of the island when you visit it
// we also have to keep track of where we backtracked within the path to ensure uniqueness amount different island shapes
// this is done with island += 's' after dfs has occured