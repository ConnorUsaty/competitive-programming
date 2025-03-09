/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int,int>> events;
        for(const auto& employee : schedule){
            for(const auto& interval : employee){
                events.push_back({interval.start, 1});
                events.push_back({interval.end, -1});
            }
        }

        sort(events.begin(), events.end());

        vector<Interval> ans;
        int curr_events = 0;
        int start = -1;
        for(const auto& e : events){
            if(curr_events==0 && start!=-1 && start != e.first){
                ans.push_back({start, e.first});
            }
            curr_events += e.second;
            start = e.first;
        }
        return ans;
    }
};
