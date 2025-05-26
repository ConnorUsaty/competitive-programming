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