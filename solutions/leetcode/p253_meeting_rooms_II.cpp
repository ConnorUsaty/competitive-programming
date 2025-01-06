class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int>> times;
        for(auto it : intervals){
            times.push_back({it[0], 1});
            times.push_back({it[1], -1});
        }
        sort(times.begin(), times.end());

        int curr=0, ans=0;
        for(auto t : times){
            curr += t[1];
            ans = max(ans, curr);
        }
        return ans;
    }
};

// almost always useful to sort intervals and have some sort of order to them for interval problems
// sort is ascending by default in c++