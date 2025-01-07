class Solution {
public:
    int makeStringGood(string s) {
        vector<int> cnt(26, 0);
        for(const char& c : s){
            cnt[c-'a']++;
        }

        int mx = -1;
        for(const int& n : cnt){
            mx = max(mx, n);
        }

        int ans = 1e9;
        // iterate over all possible final freqs to make s good
        for(int i=1; i<mx+1; ++i){
            vector<int> dp(27, 0);

            // iterate over each char in alphabet
            for(int j=25; j>=0; --j){
                if(cnt[j]>=i || i-cnt[j]<cnt[j]){
                    // go to target -> by either adding or deleting
                    dp[j] = dp[j+1] + abs(cnt[j]-i);
                } else {
                    // go to zero -> by deleting all
                    dp[j] = dp[j+1] + cnt[j];
                }
                // deleting from curr and adding to prev -> optimized with swaps
                if(j<25 && cnt[j+1]<i){
                    int dels = (i>cnt[j]) ? cnt[j] : cnt[j]-i;
                    int adds = i-cnt[j+1];
                    dp[j] = min(dp[j], dp[j+2]+adds+dels-min(dels, adds));
                }
            }
            ans = min(ans, dp[0]);
        }
        return ans;
    }
};

// at each index we have three main choices
// increase to target
// decrease to 0
// swap with adjacent element

// can choose between the first two immediately by checking if closer to target or zero
// can check for third option after by checking the 