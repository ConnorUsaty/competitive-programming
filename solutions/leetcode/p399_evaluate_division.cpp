using psd = pair<string,double>;

class Solution {
private:
    double dfs(string start, string end, double curr,
            unordered_set<string>& visited, unordered_map<string,vector<psd>>& adj){
                
        if(adj.find(start)==adj.end() || adj.find(end)==adj.end()) return -1;
        if(start==end) return curr;

        visited.insert(start);
        for(const auto& [v, w] : adj[start]){
            if(visited.find(v) == visited.end()){
                double path = dfs(v, end, curr*w, visited, adj);
                if(path != -1) return path;
            }
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<psd>> adj;
        for(int i=0; i<static_cast<int>(equations.size()); ++i){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        vector<double> ans;
        for(int i=0; i<static_cast<int>(queries.size()); ++i){
            unordered_set<string> visited;
            ans.push_back(dfs(queries[i][0], queries[i][1], 1.0, visited, adj));
        }
        return ans;
    }
};

// graphs are really good for representing relationships
// can be used for hierarchy orderings (topological sort)
// can be used for unit conversions (weighted edges)
// can be used for any kind of interaction of relationships



// BFS SOLUTION:

class Solution {
private:
    double bfs(string& start, string& end, unordered_map<string,vector<pair<string,double>>>& adj){
        queue<pair<string,double>> q;
        unordered_set<string> visited;
        q.push({start, 1.0});
        visited.insert(start);

        while(!q.empty()){
            auto [u, d] = q.front();
            q.pop();

            if(u == end) return d;

            for(auto& [v, w] : adj[u]){
                if(visited.find(v) == visited.end()){
                    q.push({v, d*w});
                    visited.insert(v);
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0; i<equations.size(); ++i){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        vector<double> ans;
        for(auto& q : queries){
            if(adj.find(q[0]) == adj.end() || adj.find(q[1]) == adj.end()) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(bfs(q[0], q[1], adj));
            }
        }
        return ans;
    }
};