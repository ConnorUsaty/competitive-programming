class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = static_cast<int>(profit.size());
        
        vector<int> ranks(n);
        iota(ranks.begin(), ranks.end(), 0);
        sort(ranks.begin(), ranks.end(), [&endTime](int i, int j) {
            return endTime[i] < endTime[j];
        });

        vector<int> dp(n, 0);
        dp[0] = profit[ranks[0]];

        for(int rank=1; rank<n; ++rank) {
            int i = ranks[rank];
            int start = startTime[i];
            int end = endTime[i];
            dp[rank] = profit[i];

            if(endTime[ranks[0]] <= start) {
                int l=0, r=rank;
                while(l<=r) {
                    int m=l+(r-l)/2;
                    if (endTime[ranks[m]] <= start) {
                        l = m+1;
                    } else {
                        r = m-1;
                    }
                }
                l = (l==0 ? l : l-1);
                dp[rank] += dp[l];
            }
            dp[rank] = max(dp[rank], dp[rank-1]);
        }
        return dp[n-1];
    }
};

// binary search into past to find first one that does NOT overlap
// dp[i] = max(dp[i-1], dp[bin search res] + profit[i]) -> needs to be sorted by end pt
// start and end being equal is NOT an overlap