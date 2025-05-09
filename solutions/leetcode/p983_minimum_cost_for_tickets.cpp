class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last_day = days[days.size()-1];
        vector<int> dp(last_day+1, INT_MAX);
        dp[0]=0;
        int j=0;
        for(int i=1; i<=last_day; ++i){
            if(days[j]!=i){
                dp[i] = dp[i-1];
                continue;
            }
            
            if(i-7>=0){
                dp[i] = dp[i-7]+costs[1];
            }else{
                dp[i] = costs[1];
            }
            if(i-30>=0){
                dp[i] = min(dp[i], dp[i-30]+costs[2]);
            }else{
                dp[i] = min(dp[i], costs[2]);
            }
            dp[i] = min(dp[i], dp[i-1]+costs[0]);
            j++;
        }
        return dp[last_day];
    }
};

// dp[i] = min cost to do all travelling up to and including day i

// since days[i] is bounded by 365 we can take the last_day as n and create a dp array of size n
// at each day we check if we should buy a ticket that continues to this day
// if we should then check which ticket is best
// continue for all i until last_day

// when we have a bunch of different options it is nice to have them by index in a dp array
// then when we have to make a new choice we can easily build off of optimal past choices