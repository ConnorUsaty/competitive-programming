class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int i, set<int>& curr, set<int>& visited){
        if(curr.find(i) != curr.end()) return true;
        if(visited.find(i) != visited.end()) return false;

        curr.insert(i);
        visited.insert(i);

        for(int& j : adj[i]){
            if (dfs(adj, j, curr, visited)) return true;
        }
        curr.erase(i);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        set<int> visited;
        for(int i=0; i<numCourses; ++i){
            if(visited.find(i) == visited.end()){
                set<int> curr;
                if (dfs(adj, i, curr, visited)) return false;
            }
        }
        return true;
    }
};

// wont be able to take all courses if theres a cycle
// check for cycle with dfs

// have to remove node from curr before returning

// dfs process -> check base case / requirements -> mark as visited -> dfs to adj -> return