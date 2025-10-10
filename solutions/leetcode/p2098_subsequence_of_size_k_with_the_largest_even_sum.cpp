class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        vector<int> evens;
        vector<int> odds;
        for(const int& n : nums) {
            if (n&1) {
                odds.push_back(n);
            } else {
                evens.push_back(n);
            }
        }
        if((k&1) && evens.empty()) return -1;

        sort(odds.begin(), odds.end(), greater<>());
        sort(evens.begin(), evens.end(), greater<>());

        int i=0, j=0;
        long long ans=0;
        for(int m=0; m<k; ++m) {
            if(i<evens.size() && (j>=odds.size() || evens[i]>odds[j])) {
                ans += evens[i];
                i++;
            } else {
                ans += odds[j];
                j++;
            }
        }

        if(ans&1) {
            long long orig = ans;
            if(i>0 && j<odds.size()) {
                ans = orig-evens[i-1]+odds[j];
            } else {
                ans = -1;
            }
            if(j>0 && i<evens.size()) {
                ans = max(ans, 1LL*orig-odds[j-1]+evens[i]);
            }
        }
        return ans;
    }
};

// any subseq of length k s.t. sum is even

// return MAX sum or -1 if no even sums
// only impossible if k odd and NO evens

// iff MAX sum odd -> take out smallest even -> add largest odd
// OR take out smallest odd -> add largest even
