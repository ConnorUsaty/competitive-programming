class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;

        for (int i=0; i<=farthest && farthest<nums.size()-1; ++i) {
            farthest = max(farthest, i+nums[i]);
        }

        return farthest>=nums.size()-1;
    }
};

// Since we are just checking whether we can make it or not, just keep track of the farthest possible position we could be in at each index
// If we get to an index that is farther than farthest than we know it is impossible
// If we get to the last index than we know that is is possible