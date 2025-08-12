class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9+7;
        long long n_odds=0, n_evens=1, sm=0, ans=0;

        for(auto& a : arr){
            sm = (sm + a) & 1;

            if(sm&1) {
                ans += n_evens;
                n_odds++;
            }
            else {
                ans += n_odds;
                n_evens++;
            }
        }
        
        return static_cast<int>(ans % MOD);
    }
};

// adding even + even = even
// adding even + odd = odd
// adding odd + odd = even

// PAY ATTENTION TO SUBARRAY VS SUBSEQUENCE
// accidentally solved for subsequences at first lol