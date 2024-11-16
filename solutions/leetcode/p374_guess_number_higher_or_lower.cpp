/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,r=n;
        long long m;

        int res = -2;
        while(res!=0){
            m = (r+l)/2;
            res = guess(m);
            if(res==-1)r=m-1;
            else if(res==1)l=m+1;
        }
        return m;
    }
};

// Use binary search on ans to acheive O(logn) time
// Can also use while l<r if they overlap then we have found ans or ans doesn't exist in list