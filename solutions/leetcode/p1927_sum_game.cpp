class Solution {
public:
    bool sumGame(string num) {
        const int n = (int)num.size();

        int cnt1=0, sm1=0;
        for(int i=0; i<n/2; ++i) {
            if(num[i]=='?') cnt1++;
            else sm1 += num[i]-'0';
        }
        int cnt2=0, sm2=0;
        for(int i=n/2; i<n; ++i) {
            if(num[i]=='?') cnt2++;
            else sm2 += num[i]-'0';
        }

        if((cnt1+cnt2) & 1) return true;

        // lower sum side = 1
        if(sm1>sm2) {
            swap(sm1, sm2);
            swap(cnt1, cnt2);
        }
        if(cnt2>cnt1) return true;

        int diff = sm2-sm1;
        return diff > (((cnt1 - cnt2)/2) * 9) || diff < (((cnt1 - cnt2 + 1)/2) * 9);
    }
};

// anytime theres an odd num of '?' Alice should be able to win
// if one side is already higher and the other has less than diff < 9*cnt/2

// for BOB win:
// total number of '?' MUST be even
// diff MUST be <= (lower_sum_freq['?'] - higher_sum_freq['?'])/2 * 9
// else ALICE win

// Bob can at max increase one side by (lower_sum_freq['?'] - higher_sum_freq['?'])/2 * 9