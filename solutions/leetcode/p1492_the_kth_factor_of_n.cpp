class Solution {
public:
    int kthFactor(int n, int k) {
        int d=1;
        for(; d*d<=n; ++d){
            if(n%d==0 && --k==0) return d;
        }
        d--;
        if(d*d==n) d--;
        for(; d>=1; --d){
            if(n%d==0 && --k==0) return n/d;
        }
        return -1;
    }
};

// we only have to go up to the square, then we can continue back down and return the opposite
// a lot of math problems like this can be solved in O(sqrt(n))
// if checks only need to be done once or twice do them outside of loop
