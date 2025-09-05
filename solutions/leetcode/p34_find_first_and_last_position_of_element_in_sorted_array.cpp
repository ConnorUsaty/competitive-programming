class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto r = std::upper_bound(nums.begin(), nums.end(), target);
        auto l = std::lower_bound(nums.begin(), nums.end(), target);

        if(l==nums.end() || *l != target) {
            return vector<int>{-1, -1};
        }
        auto l_idx = static_cast<int>(std::distance(nums.begin(), l));
        auto r_idx = static_cast<int>(std::distance(nums.begin(), r)) - 1;
        return vector<int>{l_idx, r_idx};
    }
};

// std::upper_bound returns iterator to first element > target
// std::lower_bound returns iterator to first element >= target
// returns arr.end() if nothing found

// can get idx using std::distance(arr.begin(), it);
// have to static cast to int for braced init of vector<int>