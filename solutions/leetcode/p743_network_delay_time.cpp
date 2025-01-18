typedef pair<int,int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1); // adj list
        for(const auto& t : times){
            adj[t[0]].push_back({t[2],t[1]});
        }

        int ans = 0;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        vector<int> visited(n+1, 0);
        visited[0] = 1;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        while(pq.size()>0){
            pii curr = pq.top();
            pq.pop();
            if(visited[curr.second]) continue;
            visited[curr.second] = 1;
            ans = curr.first;

            for(const auto& it : adj[curr.second]){
                if(!visited[it.second] && curr.first + it.first < dist[it.second]){
                    dist[it.second] = curr.first + it.first;
                    pq.push({dist[it.second], it.second});
                }
            }
        }
        for(const int& v : visited) if(!v) return -1;
        return ans;
    }
};


// shortest path in weighted graph with non-neg edges from single source -> Dijkstras O(ElogV) time, O(E) space
// typedef pair<int,int> pii; would save implementation time
// have to pass in all 3 args to pq to use as minHeap
// can create adj with 2D vector of pii
