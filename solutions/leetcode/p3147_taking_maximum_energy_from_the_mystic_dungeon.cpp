class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int n = energy.size();

        int ans = INT_MIN;
        for(int i=0; i<k; ++i) {
            int res = 0;
            for(int j=i; j<n; j+=k) {
                res = max(res, 0);
                res += energy[j];
            }
            ans = max(ans, res);
        }
        return ans;
    }
};

// kadanes k times

// O(n) time, O(1) memory