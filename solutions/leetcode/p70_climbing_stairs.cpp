class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;

        int p1=3, p2=2;
        for(int i=4; i<=n; ++i){
            p1 += p2;
            p2 = p1-p2;
        }
        return p1;
    }
};

// can build on subproblems
// i.e. ways to get to step 4 = (ways to step 3) + (ways to step 2)