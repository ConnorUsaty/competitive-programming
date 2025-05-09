class Solution {
private:
    void dfs(int u, const vector<vector<int>>& adj, vector<int>& q, vector<int>& ans){
        if(ans[u]==-1) ans[u]=u;

        for(const int& v : adj[u]){
            if(q[u]<q[v]){
                q[v]=q[u];
                ans[v]=ans[u];
                dfs(v, adj, q, ans);
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=(int)quiet.size();
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(auto& e : richer){
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; ++i){
            if(in[i]==0) q.push(i);
        }

        vector<int> order;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);

            for(const int& v : adj[u]){
                if(--in[v]==0){
                    q.push(v);
                }
            }
        }

        vector<int> ans(n,-1);
        for(int i=0; i<n; ++i){
            dfs(order[i], adj, quiet, ans);
        }
        return ans;
    }
};

// since we want to iterate from richest to least, get topological order of edges

// build graph to get ordering
// iterate over graph from richest to least rich
// at each node set ans[node->val] = min(quiet[y]) seen so far

// graphs are really good for anything that requires relations or ordering between people
// even converting units graphs are good for because of the relation between units and the weight of the edges can be the conversion
