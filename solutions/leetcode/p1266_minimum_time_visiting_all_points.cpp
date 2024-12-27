class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int px = points[0][0];
        int py = points[0][1];
        int total_moves=0;
        for(int i=1; i<points.size(); ++i){
            int cx = points[i][0];
            int cy = points[i][1];
            int dx = abs(px-cx);
            int dy = abs(py-cy);
            int diag_moves = min(dx, dy);
            total_moves += diag_moves + dx-diag_moves + dy-diag_moves;
            px = cx;
            py = cy;
        }
        return total_moves;
    }
};

// just greedily take diagonal as far as possible, then take straight y or straight x until point reached
// add the difference to account for seconds