class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });

        int ans = 0;
        std::map<int,int> event_mp; // {start, end} of interval

        for(const vector<int>& e : events) {
            auto it = event_mp.upper_bound(e[0]);

            if(it == event_mp.begin()) {
                ans++;
                int end = e[0];
                if(it->first == e[0]+1) {
                    end = it->second;
                    event_mp.erase(it);
                }
                event_mp.insert({e[0], end});
                continue;
            }

            auto prev_it = std::prev(it);
            if(prev_it->second < e[0]-1) {
                ans++;
                int end = e[0];
                if(it!=event_mp.end() && it->first == e[0]+1) {
                    end = it->second;
                    event_mp.erase(it);
                }
                event_mp.insert({e[0], end});
            }
            else if(prev_it->second < e[1]) {
                ans++;
                prev_it->second++;
                if(it!=event_mp.end() && prev_it->second == it->first-1) {
                    prev_it->second = it->second;
                    event_mp.erase(it);
                }
            }
        }
        return ans;
    }
};

// sort by end date and greedily attend ?

// basically at every event e, we need to check if any slot in its interval is avail

// get mp.lower_bound 
// if > start take start
// if <= start but val < end, take first avail, update end
// need to check std::prev and std::next to check if we should be merging

// O(nlogn)

// std::map or std::set can be a really good way to store intervals in a sorted order because they have built in O(logn) searchs with lower_bound and upper_bound
// important to remember that you are mapping the start of the interval to the end, so just because the lower_bound start is > what you are trying to insert this does NOT mean that std::prev(it)->second doesnt overlap