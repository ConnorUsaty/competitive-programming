typedef pair<int,int> pii;
typedef long long ll;

class Solution {
private:
    const ll MOD = 1e9+7;
    
    void dfs(vector<int>& ans, ll curr, int i, vector<vector<pii>>& adj){
        ans[i] = (curr % MOD);

        ll orig = curr;
        for(auto& a : adj[i]){
            if(ans[a.first] == -1){
                curr = ((curr % MOD) * (a.second % MOD)) % MOD;
                dfs(ans, curr, a.first, adj);
                curr = orig;
            }
        }
    }
    
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=(int)conversions.size();
        
        vector<vector<pii>> adj(n+1);
        for(auto& c : conversions){
            adj[c[0]].push_back({c[1],c[2]});
        }

        vector<int> ans(n+1, -1);
        dfs(ans, 1LL, 0, adj);
        return ans;
    }
};