class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        while(l<=r){
            long long m = l+(r-l*1LL)/2;
            if(m*m > x){
                r = m-1;
            } else if (m*m < x) {
                l = m+1;
            }
            else {
                return m;
            }
        }
        return (l==0 ? l : l-1);
    }
};

// bin search to find first int n where n*n > x, then ans = n-1
// can perform binary search on ans -> O(logn) time, O(1) space
// always use while l<=r and use else on r to push r over l so that l is at intended index
