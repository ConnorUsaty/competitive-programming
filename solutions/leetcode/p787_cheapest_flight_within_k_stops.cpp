typedef tuple<int,int,int> tiii;
typedef pair<int,int> pii;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> adj(n); // adj[u] = {{v,w}, ...}
        for(auto& f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        priority_queue<tiii, vector<tiii>, greater<>> pq; // {cost, v, stop_num}
        vector<int> visited(n, INT_MAX);
        pq.push({0,src,0});

        while(!pq.empty()){
            auto [w, u, s] = pq.top();
            pq.pop();

            if(u==dst) return w;
            if(visited[u]<=s || s==k+1) continue;
            visited[u]=s;

            for(const auto& [v,vw] : adj[u]){
                pq.push({w+vw,v,s+1});
            }
        }
        return -1;
    }
};

// shortest path from s to d in weighted graph with no neg weight edges -> DJIKSTRAS
// the first time we visit a node we know that is the lowest cost path
// however since we are constrained by num of nodes within path, we must consider shorter paths with larger cost
// therefore we do not mark as visited or unvisited or check if the new cost is lower than previous cost
// we just mark visited as number of stops and push all new paths regardless of weight as long as the path has <= k stops