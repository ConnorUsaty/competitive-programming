class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited){
        visited[u] = 1;
        for(const int& v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(i, adj, visited);
                components++;
            }
        }
        return components;
    }
};

// dfs solution:
// O(V+E) time
// O(V+E) space

// can also be done using disjoint set union (union find) to achive O(V) space, and to check each edge once, even though its undirected
// start with components = n, for each edge if the two nodes have different representitives (are in different disjoint sets), combine them into one set and components -= 1
// if they are already in the same disjoint set, do nothing