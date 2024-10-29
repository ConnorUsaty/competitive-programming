class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0) { // Runs until all ones removed
            n &= (n - 1); // Moves next one to end and then removes it
            count++; // Count the removal of ones
        }
        return count;
    }
};