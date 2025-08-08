class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return num;
        
        return (31-__builtin_clz(num)) + (__builtin_popcount(num));
    }
};

// ans = (MSB index + 1) + (num of bits set - 1)
// ans = (MSB index) + (num of bits set)