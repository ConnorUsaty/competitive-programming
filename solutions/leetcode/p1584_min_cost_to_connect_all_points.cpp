typedef pair<int,int> pii;

class Solution {
private:
    int dist(const vector<int>& p1, const vector<int>& p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<int> used;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // use [0] as starting node
        used.insert(0);
        for(int i=1; i<points.size(); ++i){
            int w = dist(points[0], points[i]);
            pq.push({w, i});
        }

        int ans = 0;
        while(used.size() < points.size()){
            pii u = pq.top(); pq.pop();

            if(used.find(u.second)!=used.end()) continue;

            used.insert(u.second);
            ans += u.first;

            for(int i=1; i<points.size(); ++i){
                if(used.find(i) == used.end()){
                    int w = dist(points[u.second], points[i]);
                    pq.push({w, i});
                }
            }
        }
        return ans;
    }
};

// min cost to connect a weighted, undirected graph -> minimum spanning tree -> prims algorithm

// O(ElogV) time complexity -> for each edge potentially pushing a vertex
// O(V+E) space -> for V vertexes in the used set, and E edges in the priority_queue

// Prims algorithm -> minimum spanning tree
// set of used
// edges in min heap
// start from any vertex, take min edge that doesn't create a cycle (connected to a vertex
// that is not in used), update available edges, repeat until used size = points size