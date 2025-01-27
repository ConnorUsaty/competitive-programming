const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < heights.size() && 
                nc >= 0 && nc < heights[0].size() && 
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]
               ) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        
        return res;
    }
};

// can find which cells are able to flow into the pacific or atlantic seperately
// then the answer is simply the intersection of these 2 sets

// to find which cells can flow in perform dfs from all cells that touch each ocean respectively

// dfs -> check if solved (if applicable), check valid, mark visited, visit all directions, unmark (if applicable), return result (if applicable)
// can iterate over directions vector for cleaner code as opposed to 4 dfs calls