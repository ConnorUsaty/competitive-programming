class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, curr=0;

        for(const int& n : gain){
            curr += n;
            ans = max(ans, curr);
        }

        return ans;
    }
};