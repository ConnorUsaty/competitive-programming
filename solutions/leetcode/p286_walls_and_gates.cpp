typedef pair<int,int> pii;
const long long INF = 2147483647;
const vector<pii> directions = {{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
private:
    bool valid(int i, int j, vector<vector<int>>& rooms){
        return (i>=0 && i<rooms.size() && j>=0 && j<rooms[0].size() && rooms[i][j]==INF);
    }

    void BFS(queue<pii> Q, vector<vector<int>>& rooms){
        int dist = 0;

        while(!Q.empty()){
            // do size check before anything else
            int s = Q.size();
            for(int k=0; k<s; ++k){
                pii curr = Q.front();
                Q.pop();
                for(auto d : directions){
                    int nx = curr.first+d.first;
                    int ny = curr.second+d.second;
                    if(valid(nx, ny, rooms)){
                        // mark as visited WHEN PUSHING TO Q
                        // need to do so to avoid repushing multiple times
                        rooms[nx][ny] = dist+1;
                        Q.push({nx,ny});
                    }
                }
            }
            dist++;
        }
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pii> Q;
        for(int i=0; i<rooms.size(); ++i){
            for(int j=0; j<rooms[i].size(); ++j){
                if(rooms[i][j] == 0){
                    Q.push({i, j});
                }
            }
        }
        // Start BFS from all gates at once
        BFS(Q, rooms);
    }
};


// Need to remember to set val / mark as visited at the same time it is pushed to Q to avoid pushing same node multiple times and re visiting for no reason
// Can start BFS outward from all gates at once by just building Q then BFS with all gates in Q rather than calling BFS() from every gate
// Do size check before anything else when doing BFS
// queue<T> has front(), push(), pop()