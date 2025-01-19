class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int opn_cnt=0;
        for(const char& c : s){
            if(c=='(') opn_cnt++;
            else if(c==')'){
                if(opn_cnt){
                    opn_cnt--;
                } else {
                    ans++;
                }
            }
        }
        return ans + opn_cnt;
    }
};
