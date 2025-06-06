class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());

        auto check = [&piles, &h](int m){
            int hours=h;
            for(int i=0; i<(int)piles.size(); ++i){
                hours -= (piles[i]/m + (piles[i]%m ? 1 : 0));
            }
            return hours>=0;
        };

        while(l<=r){
            int m = l+(r-l)/2;

            if(check(m)){
                r=m-1;
            } else {
                l=m+1;
            }
        }
        return l;
    }
};

// O(nlogn) time -> logn for binary search, n for the check() of each m
// O(1) space

// binary search on an array requires ordering, but binary search does not have to be performed on the input
// if you are checking from x to n trying to find the first solution that works, you can likely use binary search on the answer to optimize
// instead of checking 1,2, ..., etc. or n, n-1, ..., etc. perform checks using binary search to find the ans in O(n * check complexity) -> performing binary search O(logn * check complexity) on n elements
