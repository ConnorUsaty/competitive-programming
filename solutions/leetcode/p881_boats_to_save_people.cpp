class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int ans=0, l=0, r=people.size()-1;
        while(l<r) {
            if (limit - people[r] >= people[l]) {
                l++;
            }
            r--;
            ans++;
        }
        if(r==l) ans++;
        return ans;
    }
};

// always best to try and pair the biggest and smallest person
// put biggest person in boat -> check if still room for smallest