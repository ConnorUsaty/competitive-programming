class Solution {
private:
    bool check(int k, int h, vector<int>& piles){
        for(int i=0; i<piles.size(); ++i){
            h -= (piles[i]/k);
            if(piles[i]%k) h--;
            if(h<0) return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=1e9;
        while(l<=r){
            int m = l+(r-l)/2;
            if(!check(m, h, piles)){
                l=m+1;
            }
            else {
                r=m-1;
            }
        }
        return l;
    }
};

// binary search requires ordering, but binary search does not have to be performed on the input
// if you are checking from x to n trying to find the first solution that works, you can likely use binary search on the answer to optimize
// instead of checking 1,2, ..., etc. or n, n-1, ..., etc. perform checks using binary search to find the ans in O(nlogn) -> performing binary search O(logn) on n elements
