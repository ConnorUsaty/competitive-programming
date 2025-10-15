class Solution {
private:
    bool dfs_bob(int u, int time, vector<vector<int>>& adj, unordered_set<int>& vis, unordered_map<int,int>& bob_mp) {
        if(u == 0) {
            bob_mp.insert({u, time});
            return true;
        }

        bool flag = false;;
        for(const int& v : adj[u]) {
            if(vis.insert(v).second) {
                // check if any path through this node leads to node 0
                flag |= dfs_bob(v, time+1, adj, vis, bob_mp);
            }
        }
        if (flag) {
            bob_mp.insert({u, time});
            return true;
        }
        return false;
    }

    int dfs_alice(int u, int time, vector<vector<int>>& adj, unordered_set<int>& vis, unordered_map<int,int>& bob_mp, vector<int>& amount) {
        int res = INT_MIN;
        for(const int& v : adj[u]) {
            if(vis.insert(v).second) {
                // get max of all child paths
                res = max(res, dfs_alice(v, time+1, adj, vis, bob_mp, amount));
            }
        }
        if(res == INT_MIN) res = 0;

        auto it = bob_mp.find(u);
        if(it==bob_mp.end() || it->second>time) {
            res += amount[u];
        }
        else if(it->second == time) {
            res += amount[u] / 2;
        }

        return res;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n = static_cast<int>(amount.size());

        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> vis;
        unordered_map<int,int> bob_mp; // {node, bob_vis_time}
        vis.insert(bob);
        dfs_bob(bob, 0, adj, vis, bob_mp);

        vis = unordered_set<int>();
        vis.insert(0);
        return dfs_alice(0, 0, adj, vis, bob_mp, amount);
    }
};

// evaluate bobs journey to node 0
// for each node in his path mark it as 0 at some timestamp t, 
// where t is the timestep AFTER bob visits it (since they both get val if same time)

// we can also evaluate the sum on the way down then do ans = max(ans, sum) if it is a leaf, rather than getting max of all children at the top