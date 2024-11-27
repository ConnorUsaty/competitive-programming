class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        int skip=0;
        for(int i=s.length()-1;i>=0;--i){
            if(s[i]=='*'){
                skip++;
            }
            else if(skip>0){
                skip--;
            }
            else {
                stk.push(s[i]);
            }
        }

        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};