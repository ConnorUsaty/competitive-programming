class Solution {
public:
    int maxJump(vector<int>& stones) {
        if((int)stones.size() == 2) return stones[1]-stones[0];
        
        int ans = 0;
        for(int i=2; i<(int)stones.size(); ++i){
            ans = max(ans, stones[i]-stones[i-2]);
        }
        return ans;
    }
};

// the frog has to take the jump on the way there or the way back
// even with the most optimal selection we have to take a jump at min 2 indexes away
// therefore min jump dist is max of 2 indexes apart