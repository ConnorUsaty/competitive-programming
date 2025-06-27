using vvi = vector<vector<int>>;

class Solution {
private:
    void dfs(int u, vvi& cnt, vvi& adj, vector<int>& vis, vector<int>& ans, string& labels){
        vis[u] = 1;
        cnt[u][labels[u] - 'a']++;

        for(int const & v : adj[u]){
            if(!vis[v]){
                dfs(v, cnt, adj, vis, ans, labels);
                for(int i=0; i<26; ++i){
                    cnt[u][i] += cnt[v][i];
                }
            }
        }
        ans[u] = cnt[u][labels[u] - 'a'];
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto const & e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);
        vector<int> visited(n, 0);
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        for(int i=0; i<n; ++i){
            if(!visited[i]) dfs(i, cnt, adj, visited, ans, labels);
        }
        return ans;
    }
};

// dfs to bottom of tree
// keep cnt[i][j] = cnt at node i and below of letter j

// can also pass in int parent and check if v == parent instead of checking for !vis[v]