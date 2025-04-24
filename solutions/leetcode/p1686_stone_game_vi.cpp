class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = (int)aliceValues.size();

        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(),
            [&](const int a, const int b){
                return aliceValues[a]+bobValues[a] > aliceValues[b]+bobValues[b];
            }
        );

        long long a=0, b=0;
        for(int i=0; i<n; ++i){
            if (i&1) {
                b += 1LL*bobValues[idxs[i]];
            } else {
                a += 1LL*aliceValues[idxs[i]];
            }
        }
        return (a==b ? 0 : (a>b ? 1 : -1));
    }
};

// alice will always want to take the stone that gives her the most points and takes the most away from bob
// therefore we sort the stones by a[i] + b[i]
// then we iterate over the sorted array counting the scores of alice and bob as they take their turns
// finally we return whether it was a tie, alice won, or bob won
