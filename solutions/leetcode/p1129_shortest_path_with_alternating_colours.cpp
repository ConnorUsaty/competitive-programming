typedef pair<int,int> pii;

class Solution {
private:
    void bfs(vector<vector<int>>& d, const vector<vector<vector<int>>>& adj){
        queue<pii> Q;
        Q.push({0,0});
        Q.push({1,0});
        d[0][0] = 0;
        d[1][0] = 0;
        
        int p_len = 0;
        while(Q.size()>0){
            int s = Q.size();
            for(int i=0; i<s; ++i){
                pii front = Q.front();
                Q.pop();
                
                int colour = front.first;
                int opp_colour = colour^1;
                int node = front.second;
                
                for(const int& v : adj[colour][node]){
                    if(d[opp_colour][v] == INT_MAX){
                        d[opp_colour][v] = p_len+1;
                        Q.push({opp_colour, v});
                    }
                }
            }
            p_len++;
        }
    }
       
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
        for(const auto& e : redEdges){
            adj[0][e[0]].push_back(e[1]);
        }
        for(const auto& e : blueEdges){
            adj[1][e[0]].push_back(e[1]);
        }
        
        vector<vector<int>> d(2, vector<int>(n, INT_MAX));
        bfs(d, adj);
        
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
            ans[i] = min(d[0][i], d[1][i]);
            ans[i] = (ans[i] == INT_MAX) ? -1 : ans[i];
        }
        return ans;
    }
};

// shortest unweighted path -> BFS

// have to build up adj lists, keeping colours seperate
// then perform BFS from start of both colours, ensure switching colours each edge
// take the min of path from red or blue start to red or blue finish of that node
