class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0]<b[0];});

        int p_start = intervals[0][0];
        int p_end = intervals[0][1];

        for(int i=1; i<(int)intervals.size(); ++i){
            int c_start = intervals[i][0];
            int c_end = intervals[i][1];

            if(p_end >= c_start){
                // overlap -> merge them
                p_end = max(p_end, c_end);
            }
            else {
                // no overlap -> push prev to ans
                ans.push_back({p_start, p_end});
                p_start = c_start;
                p_end = c_end;
            }
        }
        // have to handle last outside loop
        ans.push_back({p_start, p_end});

        return ans;
    }
};


// sorting is normally VERY helpful for interval problems, allows us to merge them in one pass, although solution still O(nlogn) due to sort();
// sort() considerably speed up on array when custom comparator passed in as lambda function for vector<>

// remember to handle last interval outside of loop and clarify constraints, if input could be empty, if all end >= start, if p_end == c_start is considered overlap, etc.