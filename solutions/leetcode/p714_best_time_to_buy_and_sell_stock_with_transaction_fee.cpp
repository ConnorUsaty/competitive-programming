class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int curr_buy=INT_MAX, curr_sell=0, curr_prof=0, ans=0;
        for(const int& p : prices){
            if(curr_sell-p>=fee && curr_prof-fee>0){
                ans += curr_sell-curr_buy-fee;
                curr_buy=INT_MAX;
                curr_sell=0;
                curr_prof=0;
            }
            curr_buy = min(curr_buy, p);
            if(p-curr_buy>curr_prof){
                curr_prof = p-curr_buy;
                curr_sell = p;
            }
        }
        if(curr_prof>=fee){
            ans += curr_prof-fee;
        }
        return ans;
    }
};

// can still use similar solution to buy and sell stock
// but need to consider fee, can only greedily buy / sell if you can be sure that you will be able to take advantage of all future opportunities
// to do this we check that curr_sell-p >= fee
// need to assign curr_prof only considering curr p as potential sell, else will lead to trying to sell items we could not have bought at curr_but
// whenever we are doing something based on prev elements in a loop, we must do a final check for the last outside the loop as it will NOT be done inside loop