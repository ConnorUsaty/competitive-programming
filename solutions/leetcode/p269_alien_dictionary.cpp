class Solution {
public:
    string alienOrder(vector<string>& words) {
        const int n = (int)words.size();

        unordered_map<char,vector<char>> adj;
        unordered_map<char,int> in;
        unordered_set<char> letters;
        for(int i=0; i<n-1; ++i) {
            int idx = 0;
            while(idx<min(words[i].size(),words[i+1].size()) && words[i][idx]==words[i+1][idx]) {
                letters.insert(words[i][idx]);
                idx++;
            }
            // equal but words[i] longer -> no possible solution
            if(idx >= words[i+1].size() && idx < words[i].size()) {
                return "";
            }
            // broke due to diff letters -> add dependancy edge
            if(idx<min(words[i].size(),words[i+1].size())) {
                char u = words[i][idx];
                char v = words[i+1][idx];
                in[u]; // init to 0 if not present
                in[v]++;
                adj[u].push_back(v);
                idx++;
            }
            while(idx<words[i].size()) {
                letters.insert(words[i][idx]);
                idx++;
            }
        }
        for(int i=0; i<words[n-1].size(); ++i) {
            letters.insert(words[n-1][i]);
        }
        int n_edge_letters = in.size();

        queue<char> q;
        for(auto& it : in) {
            if(it.second == 0) {
                q.push(it.first);
            }
        }

        string ans = "";
        while(!q.empty()) {
            char u = q.front();
            q.pop();

            ans.push_back(u);
            letters.erase(u);

            for(const char & v : adj[u]) {
                if(--in[v] == 0) q.push(v);
            }
        }
        if(ans.size() < n_edge_letters) {
            return "";
        }

        for(const char & c : letters) {
            ans.push_back(c);
        }
        return ans;
    }
};

// EDGE CASES:
// need to check that we have n_edge_letters in our ans after top sort
// else top sort stopped early due to it being an impossible order
// need to check that [i] is not a prefix to [i+1]
// need adj, in, and letters

// be explicit with types, use auto only when it helps or for structured bindings

// at each [i] scan [i] and [i+1] until first difference
// add each letter to letters set
// add directed edge words[i][j] -> words[i+1][j]
// continue for all i

// top sort resulting edges
// add them to ans in order
// add anything remaining in letters set to the end

// return ans