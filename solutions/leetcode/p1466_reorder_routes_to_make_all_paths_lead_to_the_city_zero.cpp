class Solution {
private:
    void dfs(int u, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, int& ans) {
        visited[u] = true;
        for(auto& [v, out] : adj[u]) {
            if(!visited[v]) {
                if(out) ans++;
                dfs(v, adj, visited, ans);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& c : connections) {
            adj[c[0]].push_back({c[1], 1}); // out
            adj[c[1]].push_back({c[0], 0}); // in
        }

        vector<bool> visited(n, false);
        int ans = 0;
        dfs(0, adj, visited, ans);
        return ans;
    }
};

// if edge from u to v, "flip" and process v
// edge from v to u 


// need to process all edges that go IN and OUT of a node u
// add to adj with a in/out flag
// if in, process next
// if out ans++, then process
// put edges in backwards to adj
// dfs from 0 and flip any edges required
// ans = n - flips