class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();

        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// Reverse() returns nothing, takes start and end iterator as args, end is non inclusive, i.e. nums.begin()+8 sorts until [7]