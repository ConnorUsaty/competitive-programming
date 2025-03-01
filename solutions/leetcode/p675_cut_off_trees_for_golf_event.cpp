typedef pair<int,int> pii;
const vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

class Solution {
private:
    int BFS(pii& start, pii& end, vector<vector<int>>& f){
        int dist = 0;
        
        queue<pii> Q;
        vector<vector<int>> visited(f.size(), vector<int>(f[0].size(), 0));
        Q.push(start);
        visited[start.first][start.second] = 1;
        
        while(Q.size()>0){
            int s = Q.size();
            for(int i=0; i<s; ++i){
                pii u = Q.front();
                Q.pop();
                if(u.first == end.first && u.second == end.second) return dist;
                
                for(const auto& d : dirs){
                    int nx = u.first + d[0];
                    int ny = u.second + d[1];
                    if(nx>=0 && nx<f.size() && ny>=0 && ny<f[0].size() && !visited[nx][ny]
                       && f[nx][ny]>=1){
                        Q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
            dist++;
        }
        return -1;
        
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        // 0 CANNOT walk through
        // 1 empty, CAN walk through
        // >1 has tree with height, CAN walk through
        
        // start at [0,0]
        
        // num of steps to cut all trees from smallest to largest
        
        auto comp = ([](const pair<int,pii>& a, const pair<int,pii>& b){
            return a.first > b.first;
        });
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, decltype(comp)> pq;
        
        for(int i=0; i<forest.size(); ++i){
            for(int j=0; j<forest[0].size(); ++j){
                if(forest[i][j] > 1) pq.push({forest[i][j], {i,j}});
            }
        }
        
        int ans = 0;
        pii start = {0,0};
        while(pq.size() > 0){
            pair<int,pii> t = pq.top();
            pq.pop();
            pii end = t.second;
            
            int d = BFS(start, end, forest);
            if (d == -1){
                ans = -1;
                break;
            }
            else ans += d;
            start = end;
        }
        return ans;
    }
};