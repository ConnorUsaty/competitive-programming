struct PairHash {
    int operator()(const pair<int,int> a) const {
        return a.first ^ (a.second << 12);
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int,vector<int>> mp;
        for(auto& p : points){
            mp[p[0]].push_back(p[1]);
        }
        unordered_map<pair<int,int>,int,PairHash> last;
        int ans = INT_MAX;

        for(auto& it : mp){
            int x = it.first;
            vector<int> pts = it.second;
            sort(pts.begin(), pts.end());
            for(int i=0; i<pts.size(); ++i){
                for(int j=i+1; j<pts.size(); ++j){
                    if(last.find({pts[i],pts[j]}) != last.end()){
                        ans = min(ans, (pts[j]-pts[i]) * (x-last[{pts[i],pts[j]}]));
                    }
                    last[{pts[i],pts[j]}] = x;
                }
            }
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};

// need custom hash for pair<int,int> key
// can be created with functor -> create struct and overload operator()
// functor param must be exact same i.e. pair<int,int>, NOT pair<int,int>&

// can group points by x coords then for each pair treat it as a possible right side of the rectangle and check what the minimum possible left side is