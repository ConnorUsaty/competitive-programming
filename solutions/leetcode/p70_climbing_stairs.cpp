class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1; // step - 1
        int p2 = 1; // step - 2
        for(int i=2; i<=n; ++i){
            int t = p1;
            p1 += p2;
            p2 = t;
        }
        return p1;
    }
};

// you can get to every step from step-1 or step-2
// therefore num ways to get to step = # ways step-1 + # ways step-2