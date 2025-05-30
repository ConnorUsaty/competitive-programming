using pii = pair<int,int>;

struct PairHash {
    size_t operator()(const pii& p) const {
        return (std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) >> 12));
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=static_cast<int>(nums.size());
        const vector<pii> directions = {{1,0}, {0,1}};

        vector<int> ans;
        queue<pii> q;
        unordered_set<pii, PairHash> visited;
        q.push({0,0});
        visited.insert({0,0});

        while(!q.empty()){
            int s = q.size();
            for(int k=0; k<s; ++k){
                auto [i, j] = q.front();
                q.pop();
                ans.push_back(nums[i][j]);

                for(auto& [dx, dy] : directions){
                    int nx = i+dx;
                    int ny = j+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<nums[nx].size()
                        && visited.find({nx,ny})==visited.end()){
                        q.push({nx,ny});
                        visited.insert({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};

// the traversal follows the pattern of BFS
// use structured bindings where possible to clean up code
// when creating custom hash takes in pii as param and the function must be const (guarentess it wont modify member variables)