using pii = pair<int,int>;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        unordered_set<int> visited; // key = (x * 300) + y
        queue<pii> q;
        q.push({0,0});
        visited.insert(0);

        vector<pii> directions = {{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};

        int moves = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; ++i){
                auto [cx, cy] = q.front();
                q.pop();

                if(cx==x && cy==y) return moves;

                for(auto& [dx, dy] : directions){
                    int nx = cx + dx;
                    int ny = cy + dy;
                    int key = ((nx+300) * 600) + ny + 300;
                    if(visited.find(key) == visited.end()){
                        q.push({nx,ny});
                        visited.insert(key);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

// MIN MOVES -> BFS
// contraints are -300 to 300, therefore BFS should pass
// had to modify key calculation to avoid hashing collisions
// offset all values by + 300 so that even the minimum -300 >= 0