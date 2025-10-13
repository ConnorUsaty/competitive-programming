class Solution {
private:
    int backtrack(int row, vector<int>& cols, vector<int>& diag, vector<int>& rev_diag) {
        const int n = cols.size();
        int res = 0;
        for(int col=0; col<n; ++col) {
            if(!cols[col] && !diag[row+col] && !rev_diag[row-col+n-1]) {
                cols[col] = 1;
                diag[row+col] = 1;
                rev_diag[row-col+n-1] = 1;
                if(row == cols.size()-1) res++;
                else res += backtrack(row+1, cols, diag, rev_diag);
                cols[col] = 0;
                diag[row+col] = 0;
                rev_diag[row-col+n-1] = 0;
            }
        }
        return res;
    }

public:
    int totalNQueens(int n) {
        vector<int> cols(n, 0);
        vector<int> diag(n+n-1, 0);
        vector<int> rev_diag(n+n-1, 0);
        return backtrack(0, cols, diag, rev_diag);
    }
};

// check diags with -1, +1 and +1 +1
// check row / col with vector

// classic backtracking problem
// just set variables as visited (push_back or mark)
// continue with backtracking
// then unset variables (pop_back or unmark)