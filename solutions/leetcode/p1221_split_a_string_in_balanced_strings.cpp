class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0, ans=0;
        for(char const & c : s){
            if(c=='L') cnt++;
            else cnt--;
            if(!cnt) ans++;
        }
        return ans;
    }
};