class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX, c2=INT_MAX;

        for(const int& n : nums){
            if(n<=c1) c1=n;
            else if(n<=c2) c2=n;
            else return true;
        }
        return false;
    }
};

// c1 always holdest min element seen so far, candidate for start of chain
// c2 holds a candidate for smallest element seen after a possible c1, therefore meaning if we find a value lower than this it should be the new c2, but higher it is c3 and therefore we have a valid triplet