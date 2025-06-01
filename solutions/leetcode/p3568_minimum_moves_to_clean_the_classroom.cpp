using pii = pair<int,int>;

struct PairHash {
    size_t operator()(const pii& a) const {
        return ((a.first*21) + a.second);
    }
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=static_cast<int>(classroom.size()), n=static_cast<int>(classroom[0].size());
        const pii dirs[4] = {{1,0},{-1,0},{0,1},{0,-1}};

        int sx=-1, sy=-1, l=0;
        unordered_map<pii, int, PairHash> cord_to_idx_mp;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(classroom[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                else if(classroom[i][j]=='L'){
                    cord_to_idx_mp[{i,j}] = l++;
                }
            }
        }
        if(l==0) return 0;

        int end_mask = (1 << l) - 1;
        queue<tuple<int,int,int,int>> q;
        int dist[20][20][51][1<<10] = {};
        memset(dist,0,sizeof(dist));
        dist[sx][sy][energy][0]=0;
        q.push({sx,sy,energy,0});

        while(!q.empty()){
            auto [x,y,e,mask] = q.front();
            q.pop();


            int mvs = dist[x][y][e][mask];
            if(mask == end_mask){
                return mvs;
            }
            if(--e<0) continue;

            for(auto const & [dx,dy] : dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && classroom[nx][ny]!='X'){
                    int ne = e;
                    int nmask = mask;
                    if(classroom[nx][ny]=='L'){
                        nmask |= (1 << cord_to_idx_mp[{nx,ny}]);
                    }
                    else if(classroom[nx][ny]=='R'){
                        ne = energy;
                    }
                    if(!dist[nx][ny][ne][nmask]){
                        q.push({nx,ny,ne,nmask});
                        dist[nx][ny][ne][nmask]=mvs+1;
                    }
                }
            }
        }
        return -1;
    }
};

// bfs with [i][j][mask][energy] as state

// with bfs the reason why its "optimal" is because we can assume the first time we visit a node it is the best unweighted path
// however we may need to revisit certain nodes multiple times to solve this problem
// therefore we can only prove that it is the best unweighted path for the current [mask][energy] state and thus can only mark it as visited for that state
// however we can still be sure that the first path we find where mask == end_mask is the optimal path, it is just harder to prove we are in the best intermediate state