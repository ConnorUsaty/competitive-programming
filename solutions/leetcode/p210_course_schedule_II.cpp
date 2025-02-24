class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites){
            in[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> Q;
        for(int i=0; i<numCourses; ++i){
            if(in[i] == 0){
                Q.push(i);
            }
        }
        vector<int> ans;
        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();
            ans.push_back(u);
            for(const int& v : adj[u]){
                if(--in[v] == 0){
                    Q.push(v);
                }
            }
        }
        return (int)ans.size() == numCourses ? ans : vector<int>{};
    }
};

// can use Khan's algorithm (topological sort) to get nodes in order from first to last in a DAG
// can detect cycle using topological sort by checking if ans.size() == num nodes
// if ans.size() < num nodes this means that the algo broke loop early due to a cycle

// O(V+E) time -> V for checking which have in == 0, E for counting each edge for in and --in[v] each edge later
// O(V+E) space -> V for ans / Q / in degree, E for adj list

// cannot do : {}; in tenary operator, have to do : std::vector<int>{};