class Solution {
public:
    int reverse(int x) {
        int sign=1;
        if(x<0){
            if(x == INT_MIN) return 0;
            sign = -1;
            x *= -1;
        }

        
        int ans=0;
        while(x>0){
            if(ans > INT_MAX/10) return 0;
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        return sign*ans;
    }
};