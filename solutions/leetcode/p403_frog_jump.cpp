typedef pair<int,int> pii;

struct PairHash{
    size_t operator()(const pii& p) const {
        return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second << 8);
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int last_stone = stones[stones.size()-1];
        
        queue<pii> q; // {stone, k}
        unordered_set<pii, PairHash> visited; // {stone, k}
        unordered_set<int> stone_set(stones.begin(), stones.end());

        q.push({0,0});
        visited.insert({0,0});

        while(!q.empty()){
            auto [stone, k] = q.front();
            q.pop();

            if(stone == last_stone) return true;

            for(int i=-1; i<=1; ++i){
                int target = stone+k+i;
                if(stone_set.find(target)!=stone_set.end() && visited.find({target,k+i})==visited.end()){
                    q.push({target,k+i});
                    visited.insert({target,k+i});
                }
            }
        }
        return false;
    }
};

// DP problem BUT
// can be solved with BFS within state space
// just need to account for {stone, k} the current stone and the units jumped to it
// pair<int,int> requires a custom hash
// can be made easily with a struct that overloads operator() -> functor