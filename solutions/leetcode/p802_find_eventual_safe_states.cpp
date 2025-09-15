class Solution {
private:
    void dfs(int u, vector<int>& safe, vector<vector<int>>& adj) {
        if(safe[u] != -1) return;

        int flag = 1;
        safe[u] = 0;
        for(const int & v : adj[u]) {
            dfs(v, safe, adj);
            if(safe[v] == 0) flag = 0;
        }
        safe[u] = flag;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = (int)graph.size();

        vector<int> ans;
        vector<int> safe(n, -1); // -1 = unsearched, 0 = not safe, 1 = safe
        for(int i=0; i<n; ++i) {
            if (safe[i]==-1) {
                dfs(i, safe, graph);
            }
            if (safe[i]==1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// just dfs and check if cycle
// can "memoize" answers with safe arr

// O(n + m) time
// O(n) space