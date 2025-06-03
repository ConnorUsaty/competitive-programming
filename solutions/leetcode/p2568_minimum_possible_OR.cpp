class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        uint64_t shift=0;
        while (1) {
            if(num_set.find(1 << shift) == num_set.end()){
                return (1 << shift);
            }
            shift++;
        }
        return -1;
    }
};

// if 1 is not present return 1
// if 2 is not present return 2
// if 1 and 2 are present then 3 must be expressible too
// therefore we next need to check for 4
// this pattern continues of only needed to check for powers of 2
// therefore make into set and loop until we are missing a power of 2