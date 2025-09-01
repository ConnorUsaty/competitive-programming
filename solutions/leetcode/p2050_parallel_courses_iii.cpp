class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n+1, 0);
        vector<vector<int>> adj(n+1);
        for(auto& r : relations) {
            in[r[1]]++;
            adj[r[0]].push_back(r[1]);
        }

        queue<int> q;
        for(int i=1; i<=n; ++i) {
            if(in[i] == 0) q.push(i);
        }

        vector<int> dp(n+1, 0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            dp[u] += time[u-1];

            for(auto& v : adj[u]) {
                dp[v] = max(dp[u], dp[v]);
                if(--in[v] == 0) q.push(v);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// dp[v] = min time to complete that course

// top sort to get order
// go in top sort order and set all adj nodes to dp[v] = max(dp[u] + time[u], dp[v])

// be careful of indexing (time was 0-based while everything was 1-based)
// always use top sort for forced orderings