class Solution {
private:
    void backtrack(int i, vector<int>& cols, unordered_set<int>& diag,
            unordered_set<int>& anti_diag, vector<string>& grid, vector<vector<string>>& ans){
        if(i==(int)grid.size()){
            ans.push_back(grid);
            return;
        }

        for(int j=0; j<(int)grid.size(); ++j){
            int d = i-j;
            int a = i+j;
            if(!cols[j] && diag.find(d)==diag.end() && anti_diag.find(a)==anti_diag.end()){
                grid[i][j] = 'Q';
                cols[j] = 1;
                diag.insert(d);
                anti_diag.insert(a);
                backtrack(i+1, cols, diag, anti_diag, grid, ans);
                grid[i][j] = '.';
                cols[j] = 0;
                diag.erase(d);
                anti_diag.erase(a);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> cols(n, 0);
        unordered_set<int> diag;
        unordered_set<int> anti_diag;

        vector<string> grid(n);
        for(int i=0; i<n; ++i){
            string row(n, '.');
            grid[i] = row;
        }
        
        backtrack(0, cols, diag, anti_diag, grid, ans);

        return ans;
    }
};

// go to next row, check if col valid
// check if diag valid 
// have to check and create all combinations -> BACKTRACKING