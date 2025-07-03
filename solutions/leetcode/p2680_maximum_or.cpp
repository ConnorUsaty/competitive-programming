class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> p_or(n+1, 0);
        vector<long long> s_or(n+1, 0);
        long long ans = 0;
        long long l = (1 << k);

        for (int i=0; i<n; ++i) {
            p_or[i+1] = p_or[i] | nums[i];
        }
        for (int i=n-1; i>=0; --i) {
            s_or[i] = s_or[i+1] | nums[i];
        }

        for (int i=0; i<n; ++i) {
            ans = max(ans, p_or[i] | (nums[i] * l) | s_or[i + 1]);
        }
        return ans;
    }
};