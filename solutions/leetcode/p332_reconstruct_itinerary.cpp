class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(const auto& t : tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& [_, edges] : adj){
            sort(edges.rbegin(), edges.rend());
        }

        vector<string> itinerary;
        string start = "JFK";
        dfs(start, adj, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport, unordered_map<string,vector<string>>& adj, vector<string>& itinerary){
        auto& edges = adj[airport];
        while(!edges.empty()){
            string v = edges.back();
            edges.pop_back();
            dfs(v, adj, itinerary);
        }
        itinerary.push_back(airport);
    }
};

// euler path -> visit all edges ONCE and star != finish
// have to reverse path
// access and pop_back() for O(1) operations