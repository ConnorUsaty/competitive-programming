class Solution {
public:
    int maximum69Number (int num) {
        int orig = num;

        int ans=orig, m=1;
        while(num){
            int d = num%10;
            if(d==6) ans=orig+(3*m);
            m*=10;
            num/=10;
        }

        return ans;
    }
};

// O(logn)

// just switch first from left (most sig) 6 to a 9