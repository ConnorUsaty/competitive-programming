class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int negs = 2;
        if(dividend > 0) {
            negs--;
            dividend = -dividend;
        }
        if(divisor > 0) {
            negs--;
            divisor = -divisor;
        }

        int n = divisor;
        int power = -1;
        int half_int_min = (INT_MIN >> 1);
        while(n>=half_int_min && n+n>=dividend) {
            n <<= 1;
            power <<= 1;
        }

        int q = 0;
        while(dividend <= divisor) {
            if(dividend<=n){
                q += power;
                dividend -= n;
            }
            n >>= 1;
            power >>= 1;
        }

        if (negs != 1) {
            return -q;
        }
        return q;
    }
};

// read instructions carefully -> CANNOT use mult, div, or %
// can use >> and << or += in place of *2;
// O(logn) time, O(1) space