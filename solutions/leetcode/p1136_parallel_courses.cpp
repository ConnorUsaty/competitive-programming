class Solution {
private:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& dp) {
        if(dp[u] != 0) return dp[u];

        int res = 0;
        dp[u] = -1;
        for(const int& v : adj[u]) {
            int depth = dfs(v, adj, dp);
            if (depth == -1) return -1;
            res = max(res, depth);
        }
        dp[u] = res+1;
        return res+1;
    }

public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> dp(n+1, 0);
        vector<vector<int>> adj(n+1);
        for(auto& r : relations) {
            adj[r[0]].push_back(r[1]);
        }

        for(int i=1; i<=n; ++i) {
            if(dfs(i, adj, dp) == -1) {
                return -1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};