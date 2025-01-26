class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);

        // reset slow and make fast only move 1
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

       return slow; 
    }
};

// use Floyd's cycle detection algorithm "Tortoise and Hare"
// algorithm requires two passes, as first intersection is not normally the cycle entrance
// only works in this scenario because nums range from 1 to n, i.e. all valid indexes
// many other solutions possible but they modify the original list which was unwanted
// for example can mark value as seen by doing [i] * -1 to change to negative, O(n) time, O(1) space, but modifies input
// or just using a seen set, O(n) time, O(n) space
