class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;

        for (int i=0;i<prices.size()-1;++i){
            if(prices[i]<prices[i+1]) ans += prices[i+1]-prices[i];
        }

        return ans;
    }
};

// buy at curr_min
// sell when curr_max > curr && curr_max > curr_min
// then buy curr
// always better to sell when curr_max > curr and buy new at curr

// Due to above observations we can use greedy, simply checking if we can make a profitable sale at each index and keeping track of the sum of possible profitable sales
// O(n) time, O(1) space