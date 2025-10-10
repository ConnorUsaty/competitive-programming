class Solution {
public:
    int maxScore(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 2) return 0;

        int score = std::accumulate(nums.begin(), nums.end(), 0);
        if (n&1) {
            score -= *min_element(nums.begin(), nums.end());
        } else {
            int mn_m = INT_MAX;
            for(int i=1; i<n; ++i) {
                mn_m = std::min(mn_m, nums[i] + nums[i-1]);
            }
            score -= mn_m;
        }
        return score;
    }
};