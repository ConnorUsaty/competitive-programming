using pii_t = pair<int,int>;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pii_t>> adj(n);
        for(auto const & e : edges){
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }

        vector<int> visited(n, 0);
        vector<int> dist(n, INT_MAX); // min dist from 0 will return as ans
        priority_queue<pii_t, vector<pii_t>, greater<>> pq;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();

            if(visited[u]) continue;
            visited[u] = 1;

            for(auto const & [vw, v] : adj[u]){
                if(!visited[v] && w+vw<dist[v] && w+vw<disappear[v]){
                    dist[v] = w+vw;
                    pq.push({w+vw, v});
                }
            }
        }

        for(int & d : dist){
            if(d==INT_MAX) d=-1;
        }
        return dist;
    }
};

// djikstras from node 0 but also check that dist[i] < dissapear[i] else invalid