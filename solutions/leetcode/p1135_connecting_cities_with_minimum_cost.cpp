typedef pair<int,int> pii;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto c : connections){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }

        int ans = 0;

        auto comp = [](const pii& a, const pii& b){
            return a.second>b.second;
        };
        priority_queue<pii,vector<pii>,decltype(comp)> pq;
        vector<int> cost(n+1,INT_MAX);
        vector<int> visited(n+1,0);
        pq.push({1,0});
        cost[1] = 0;

        while(!pq.empty()){
            pii tp = pq.top();
            pq.pop();
            int u = tp.first;
            int w = tp.second;
            if(w==INT_MAX) break;
            if(visited[u]) continue;

            ans += w;
            visited[u] = 1;

            for(pii& p : adj[u]){
                int v = p.first;
                int c = p.second;
                if(!visited[v] && cost[v]>c){
                    cost[v] = c;
                    pq.push({v,c});
                }
            }
        }
        
        for(int i=2; i<=n; ++i){
            if(!visited[i]) return -1;
        }
        return ans;
    }
};

// minimum spanning tree -> prims
// start at arbitary node by setting its dist to 0 and pushing to pq
// set all other cost to inf
// as each node is popped from pq update all adj's and if better path found, push to pq
// continue until all nodes connected

// used customer comparator; custom cmp decides which element gets pushed down lower in queue (heap), therefore do a.second>b.second to push a lower (towards back of pq) if a has a greater w than b 