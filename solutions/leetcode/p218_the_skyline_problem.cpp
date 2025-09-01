class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> pts; // {start, end, h}
        for(auto& b : buildings) {
            pts.push_back({b[0], b[1], b[2]}); // start
            pts.push_back({b[1], b[1], -1}); // end
        }
        sort(pts.begin(), pts.end(), std::less<>());

        vector<vector<int>> ans;
        priority_queue<vector<int>> active; // {h, end}
        int idx = 0;
        while(idx < pts.size()) {
            // process all buildings that start / end on this x
            int curr_x = pts[idx][0];
            while(idx < pts.size() && pts[idx][0] == curr_x) {
                if(pts[idx][2] != -1) active.push({pts[idx][2], pts[idx][1]});
                idx++;
            }
            // remove all inactive buildings
            while(!active.empty() && active.top()[1]<=curr_x) {
                active.pop();
            }
            // update ans
            if(ans.empty() || active.empty() || ans.back()[1] != active.top()[0]) {
                if(active.empty()) ans.push_back({curr_x, 0});
                else ans.push_back({curr_x, active.top()[0]});
            }
        }
        return ans;
    }
};

// sweepline + heap
// O(nlogn) time
// O(n) space

// we still need to create the pts vector to properly sweep line
// because we need the start and end pts separated to properly process each "important" x coordinate in order
