using ll = long long;

class Solution {
private:
    bool check(ll m, vector<int>& start, int d){
        // checks if each element can be spread m apart
        ll next = 1LL*start[0]+m;
        for(int i=1; i<(int)start.size(); ++i){
            if(1LL*start[i]+d<next) return false;
            next = max(next+m, 1LL*start[i]+m);
        }
        return true;
    }

public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        ll l=0, r=1LL*start[start.size()-1]+d;
        while(l<=r){
            ll m=l+(r-l)/2;
            if(check(m, start, d)){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return (l==0 ? 0 : l-1);
    }
};


// how to check for max possible seperation between each elements ?
// try max, then max-1, etc., O(n^2) -> too inefficient

// if we realize we are linearly checking for a specific min or max that meets a criteria we can almost always binary search instead -> O(nlogn) time