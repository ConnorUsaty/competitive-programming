class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=(int)coins.size();

        sort(coins.begin(), coins.end());

        int ans=0, curr=0;
        for(int i=0; i<n && curr<target; ++i){
            if(curr >= coins[i]-1){
                curr += coins[i];
            }
            else{
                ans++;
                curr += (curr+1);
                --i;
            }
        }
        while(curr<target){
            ans++;
            curr += (curr+1);
        }
        return ans;
    }
};