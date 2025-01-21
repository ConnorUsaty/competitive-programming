class Solution {
public:
    double myPow(double x, int n) {
        long long abs_n = abs((long)n);

        double ans = 1;

        while(abs_n){
            if(abs_n&1) ans = (ans * x);
            abs_n >>= 1;
            x *= x;
        }

        ans = (n<0) ? 1/(ans) : ans;
        return ans;
    }
};

// to handle negative n values:
// take absolute of (long)n
// iterate on that
// return 1/ans if n was < 0
// else just return ans