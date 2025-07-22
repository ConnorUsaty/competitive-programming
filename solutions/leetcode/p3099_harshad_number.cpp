class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int orig = x, dig_sum = 0;
        while(x){
            dig_sum += x % 10;
            x /= 10; 
        }
        return (orig % dig_sum == 0 ? dig_sum : -1);
    }
};