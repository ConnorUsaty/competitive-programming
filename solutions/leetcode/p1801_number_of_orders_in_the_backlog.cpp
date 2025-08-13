class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int,long long,std::greater<>> bids; // {price, qty}
        map<int,long long,std::less<>> asks; // {price, qty}

        for(auto& o : orders){
            if(o[2]==0){
                // bid
                // try to aggresively match with asks
                while(o[1]>0 && !asks.empty() && o[0]>=asks.begin()->first){
                    auto matched = std::min(o[1]*1LL, asks.begin()->second);
                    o[1] -= matched;
                    asks.begin()->second -= matched;
                    if(asks.begin()->second <= 0) {
                        asks.erase(asks.begin()->first);
                    }
                }

                // if left over (unable to aggressively fill ENTIRE order)
                // place into bids
                if(o[1]>0){
                    bids[o[0]] += o[1];
                }
            }
            else{
                // try to aggresively match with bids
                while(o[1]>0 && !bids.empty() && o[0]<=bids.begin()->first){
                    auto matched = std::min(o[1]*1LL, bids.begin()->second);
                    o[1] -= matched;
                    bids.begin()->second -= matched;
                    if(bids.begin()->second <= 0) {
                        bids.erase(bids.begin()->first);
                    }
                }

                // if left over (unable to aggressively fill ENTIRE order)
                // place into asks
                if(o[1]>0){
                    asks[o[0]] += o[1];
                }
            }
        }

        long long ans = 0;
        const long long MOD = 1e9+7;
        for(auto& [p, c] : bids){
            ans = (ans+c) % MOD;
        }
        for(auto& [p, c] : asks){
            ans = (ans+c) % MOD;
        }
        return static_cast<int>(ans);
    }
};