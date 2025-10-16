class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int n = static_cast<int>(events.size());

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&events](int i, int j) {
            return events[i][1] < events[j][1] 
                || (events[i][1]==events[j][1] && events[i][0]<events[j][0]);
        });

        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        for(int o=0; o<n; ++o) {
            int start = events[order[o]][0];
            int end = events[order[o]][1];
            int profit = events[order[o]][2];

            if(events[order[0]][1] < start) {
                int l=0, r=o-1;
                while(l<=r) {
                    int m = l+(r-l)/2;
                    if (events[order[m]][1] < start) {
                        l = m+1;
                    } else {
                        r = m-1;
                    }
                }
                l = (l==0 ? l : l-1);
                for(int i=k; i>0; --i) {
                    dp[o][i] = max(dp[o-1][i], dp[l][i-1]+profit);
                }
            }
            else {
                for(int i=k; i>0; --i) {
                    dp[o][i] = max((o>0 ? dp[o-1][i] : 0), profit);
                }
            }
        }
        return dp[n-1][k];
    }
};

// we want to connect curr event to max profit event attended sequence that does NOT overlap with curr event
// there way not always be a sequence that ended on start - 1, so we will have to bin search
// we can compress the bin search to the idxs of the events sorted in order by end
// dp[i][k] = max profit by ordered event i whilst attending k events
// at each idx we can either create a better answer by connecting curr to an old one, or the answer from last idx is better