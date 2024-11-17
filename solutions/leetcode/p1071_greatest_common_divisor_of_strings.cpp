class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2==str2+str1){
            // gcd exists
            return str1.substr(0, gcd(str1.length(),str2.length()));
        }
        else{
            // no gcd
            return "";
        }
    }
};

// string.substr(pos, len) -> returns substr of string starting at [pos] and of length len
// gcd(num1, num2) -> returns the greatest common divisor of num1 and num2