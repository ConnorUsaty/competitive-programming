class Solution {
private:
    bool intersect(const unordered_set<int>& a, const unordered_set<int>& b){
        for(const int& n : a){
            if(b.find(n)!=b.end()){
                return true;
            }
        }
        return false;
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        
        int r = (int)routes.size();

        // get all routes as sets
        vector<unordered_set<int>> rsets(r);
        for(int i=0; i<r; ++i){
            rsets[i] = unordered_set<int>(routes[i].begin(), routes[i].end());
        }

        // build adj list
        vector<vector<int>> adj(r);
        for(int i=0; i<r-1; ++i){
            for(int j=i+1; j<r; ++j){
                if(intersect(rsets[i],rsets[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // init q and visited
        queue<int> q; // val = route num, 0 to r-1
        vector<int> visited(r,0);
        for(int i=0; i<r; ++i){
            if(rsets[i].find(source) != rsets[i].end()){
                q.push(i);
                visited[i] = 1;
            }
        }

        int buses = 1;
        while(!q.empty()){
            int s = (int)q.size();
            for(int i=0; i<s; ++i){
                int u = q.front();
                q.pop();
                if(rsets[u].find(target) != rsets[u].end()) return buses;

                // go to all adj routes
                for(const int& v : adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};

// shortests unweighted path -> BFS
// think about how to turn into graph (how to create an adj list)
// can think of each route as a vertex, and it can be adj to all routes that it has an intersection with (at least one stop in common)
// consider edge cases (start == finish) (dont have to get on bus)
// init q and visited with all possible start points and search from each at the same time to guarentee first visit to a route that contains finish is the shortest
