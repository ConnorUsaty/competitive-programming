class Solution {
private:
    int squareDigSum(int n) {
        int ans = 0;
        while(n){
            int t = n%10;
            ans += t*t;
            n /= 10;
        }
        return ans;
    }

public:
    bool isHappy(int n) {
        int slow=n, fast=n;
        do {
            slow = squareDigSum(slow);
            fast = squareDigSum(fast);
            fast = squareDigSum(fast);
        } while (fast != 1 && slow != fast);
        return fast == 1;
    }
};

// use floyds cycle finding algorithm with fast and slow vars
// use do while loops when you need to guarentee it enters loop AT LEAST ONCE -> Does not check loop condition until after performing loop, guarenteeing first execution