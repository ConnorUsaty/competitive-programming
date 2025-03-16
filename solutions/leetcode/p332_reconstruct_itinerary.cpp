class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(const auto& t : tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& [u, v_list] : adj){
            sort(v_list.rbegin(), v_list.rend());
        }

        vector<string> ans;
        string start = "JFK";
        dfs(start, ans, adj);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(const string& curr, vector<string>& ans, unordered_map<string,vector<string>>& adj){
        while(!adj[curr].empty()){
            string v = adj[curr].back();
            adj[curr].pop_back();
            dfs(v, ans, adj);
        }
        ans.push_back(curr);
    }
};