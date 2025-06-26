class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=(int)grid.size(), n=(int)grid[0].size();
        vector<vector<long long>> mx(m, vector<long long>(n, INT_MIN));
        vector<vector<long long>> mn(m, vector<long long>(n, INT_MAX));
        mn[0][0] = mx[0][0] = grid[0][0];

        for(int i=1; i<m; i++){
            mn[i][0] = mx[i][0] = mx[i-1][0] * grid[i][0];
        }
        for(int j=1; j<n; j++){
            mn[0][j] = mx[0][j] = mx[0][j-1] * grid[0][j];
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
               if(grid[i][j] < 0) {
                    mx[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                    mn[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                }
                else {
                    mx[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                    mn[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                }
            }
        }
        const int MOD = 1e9+7;
        int ans = mx[m-1][n-1] % MOD;
        return (ans >= 0 ? ans : -1);
    }
};