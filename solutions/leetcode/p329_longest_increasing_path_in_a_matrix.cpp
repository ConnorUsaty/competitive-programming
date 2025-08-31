class Solution {
private:
    const vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int M{};
    int N{};

    void dfs(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if(memo[i][j] != -1) return;
        memo[i][j] = 0; // mark as visited
        
        int best = 0;
        for(auto& [dx, dy] : directions) {
            int nx = i + dx;
            int ny = j + dy;
            if(nx>=0 && nx<M && ny>=0 && ny<N && matrix[nx][ny]>matrix[i][j]) {
                dfs(nx, ny, memo, matrix);
                best = max(best, memo[nx][ny]);
            }
        }
        memo[i][j] = best + 1;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();

        int ans = 1;
        vector<vector<int>> memo(M, vector<int>(N, -1));
        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                dfs(i, j, memo, matrix);
                ans = max(ans, memo[i][j]);
            }
        }
        return ans;
    }
};