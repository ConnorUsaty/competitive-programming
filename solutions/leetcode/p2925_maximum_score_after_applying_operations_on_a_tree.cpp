class Solution {
private:
    long long dfs(long long& ans, int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& values) {
        visited[u] = true;

        long long child_sm = 0;
        for(const int & v : adj[u]) {
            if(!visited[v]) {
                child_sm += dfs(ans, v, adj, visited, values);
            }
        }

        if(values[u] > child_sm && child_sm > 0) {
            // keep children alive, take value of parent
            ans += values[u];
            return child_sm;
        } else {
            // kill parent take all child values
            ans += child_sm;
            return values[u];
        }
    }
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        const int n = (int)values.size();

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long ans = 0;
        dfs(ans, 0, adj, visited, values);
        return ans;
    }
};

// great job noticing it was an N-ary tree (NOT BINARY)
// came up with and validated the optimal solution
// stated time complexities

// O(V + E) time for DFS
// O(V + E) space for DFS

// tree (not binary)
// rooted at node 0

// healthy if all paths from root to leafs != 0

// need to keep one node on each path alive
// dfs down, at each parent check if val > left + right
// if > then kill parent and keep left + right
// pass l+r upwards and check if next parent also > than that + other side