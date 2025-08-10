class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int n = (int)seats.size();

        int i=0;
        while(!seats[i]){
            i++;
        }
        int ans = i, last = i;

        for(; i<n; ++i){
            ans = max(ans, (i-last)/2);
            if(seats[i]) last = i;
        }
        ans = max(ans, n-1-last);
        return ans;
    }
};

// iterate over once
// keep track of last seated person
// ans = max(ans, (r-l)/2)

// need to think of edge cases such as to the left of the first person seated and to the right of the last person seated
// in these scenarios we do NOT need to divide by 2