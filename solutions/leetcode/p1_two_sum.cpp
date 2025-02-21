class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0; i<(int)nums.size(); ++i){
            int diff = target - nums[i];
            if(seen.find(diff) != seen.end()){
                return {seen[diff], i};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};

// O(n) time, O(n) space