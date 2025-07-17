class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int shft=0; shft<32; shft += 2){
            if(n == (1 << shft)) return true;
        }
        return false;
    }
};