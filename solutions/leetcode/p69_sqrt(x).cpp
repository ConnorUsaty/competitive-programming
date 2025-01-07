class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        int l=1, r=x;
        while(l<=r){
            int m = l+(r-l)/2;
            if(m == x/m){
                return m;
            }
            else if(m < x/m){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return l-1;
    }
};

// can perform binary search on ans -> O(logn) time, O(1) space
// always use while l<=r and use else on r to push r over l so that l is at intended index
