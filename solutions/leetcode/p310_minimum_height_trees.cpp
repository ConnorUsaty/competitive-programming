class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for(const auto& e : edges){
            in[e[0]]++;
            in[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for(int i=0; i<n; ++i){
            if(in[i]==1){
                q.push(i);
            }
        }

        vector<int> order;
        while(!q.empty()){
            order = {};
            int s = q.size();

            for(int i=0; i<s; ++i){
                int u = q.front();
                q.pop();
                order.push_back(u);

                for(const int& v : adj[u]){
                    if(--in[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        return order;
    }
};

// bfs from every node, if == min append to ans, if < min reset ans to just that node
// O(n^2), bfs O(n) from n nodes

// can use algorithm similar to topological sort and work way to top of tree from leafs