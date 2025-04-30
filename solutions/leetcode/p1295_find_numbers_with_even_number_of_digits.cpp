class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int& n : nums){
            int d = 0;
            while(n){
                n /= 10;
                d++;
            }
            if(!(d&1)) ans++;
        }
        return ans;
    }
};