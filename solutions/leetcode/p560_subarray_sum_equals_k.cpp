class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long curr=0, ans=0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0; i<(int)nums.size(); ++i){
            curr += nums[i];
            if(mp.find(curr-k) != mp.end()) ans += mp[curr-k];
            mp[curr]++;
        }
        return ans;
    }
};

// cannot use two ptr / sliding window approach due to negative values
// sliding window would work on assumption than expanding window ALWAYS increases curr sum
// and that shortening window ALWAYS decreases curr sum
// since nums[i] can be < 0 this approach does not work

// instead problem can be solved as a two sum variation where at each index we check if 
// the sum between 2 indexs at any point is k and if so increment our ans by that