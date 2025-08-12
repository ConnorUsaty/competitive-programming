class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n+1);
        vector<int> in(n+1, 0);
        for(auto& e : edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
            in[e[0]]++;
            in[e[1]]++;
        }

        vector<int> odds;
        for(int i=1; i<=n; ++i){
            if(in[i]&1) odds.push_back(i);
        }

        int odd = (int)odds.size();
        if(odd==0) return true;
        if(odd&1 || odd>4) return false;

        if(odd==2){
            for(int i=1; i<=n; ++i){
                if(adj[odds[0]].find(i) == adj[odds[0]].end()
                    && adj[odds[1]].find(i) == adj[odds[1]].end()){
                        return true;
                    }
            }
        }


        if(odd == 4){
            auto f = [&adj](int i, int j){
                return (adj[i].find(j) == adj[i].end());
            };
            // need to connect 2 to each other and 2 to each other
            // need to find a way to split them so that this can happen
            int first = odds[0];
            int second = odds[1];
            int third = odds[2];
            int fourth = odds[3];

            return (f(first, second) && f(third, fourth) ||
                f(first, third) && f(second, fourth) ||
                f(first, fourth) && f(second, third));
        }

        return false;
    }
};