class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        std::unordered_map<int,int> cnt;
        for(int i=nums.size()-1; i>=0; --i){
            if(++cnt[nums[i]]>1) return (i/3)+1;
        }
        return 0;
    }
};

// can use greedy solution, find first duplciate, you will have to remove all elements up until the duplicate regardless of how the rest of the array looks