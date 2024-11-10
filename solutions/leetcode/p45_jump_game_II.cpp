class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, ans=0, farthest=0;

        while(farthest<nums.size()-1) {
            int prev_farthest = farthest; // Need this var for loop condition
            for(int i=l;i<prev_farthest+1;++i){
                farthest = max(farthest, i+nums[i]);
            }
            l=prev_farthest+1; // Already calculated all possible jumps until this index
            ans++;
        }

        return ans;
    }
};

// Can assume reaching last index is always possible
// Can keep track of farthest we could have made it at each turn
// Once we last index becomes reachable, return num of turns