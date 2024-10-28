class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) {
            return 0;
        }

        grid[i][j] = 0;
        int size = 1;

        size += helper(grid, i+1, j);
        size += helper(grid, i-1, j);
        size += helper(grid, i, j+1);
        size += helper(grid, i, j-1);

        return size;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j]==1) {
                    ans = max(ans, helper(grid, i, j));
                }
            }
        }
        return ans;
    }
};

// Utilize dfs to search each island
// Change each visited index to 0 to mark as visited / not to dfs
// Utilize helper functions for recursion and recursion for dfs
// Remember to set your base case for recursion