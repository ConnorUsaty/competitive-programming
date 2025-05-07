class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n=(int)moveTime.size(), m=(int)moveTime[0].size();
        const vector<vector<int>> directions = { {1,0}, {0,1}, {-1, 0}, {0,-1} };

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        dist[0][0]=0;
        pq.push({dist[0][0], 0, 0});

        while(!pq.empty()){
            int w = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(visited[x][y]) continue;
            visited[x][y]=1;
            if(x==n-1 && y==m-1) return w;

            for(const auto& d : directions){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    // new weight is either curr w+1 or moveTime+1
                    int nw = (moveTime[nx][ny]>=w+1 ? moveTime[nx][ny]+1 : w+1);
                    if(nw>=dist[nx][ny]) continue; // have found shorter path previously
                    dist[nx][ny]=nw;
                    pq.push({nw,nx,ny});
                }
            }
        }
        return -1;
    }
};

// shortest path problem with specific start and end point and weighted edges and no negative weight edges -> DJIKSTRAS
// even though we start at top left we have to consider all four directions as the path has no constraint that says only right or down
// before adding to pq check if the nw should be w+1 or moveTime+1
// need a visited for djikstras but dont mark until we actually visit -> DIFF from BFS because we may push a more optimal path
// we can only guarentee it is the shortest path once we visit and pop from pq