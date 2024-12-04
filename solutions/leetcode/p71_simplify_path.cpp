class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;
        string ans;

        for(int i=0;i<path.size();++i){
            if(path[i]=='/') continue;

            string temp;
            while(i<path.size() && path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }

            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!stk.empty()) stk.pop_back();
            }
            else{
                stk.push_back(temp);
            }
        }
        
        while(!stk.empty()){
            ans += "/" + stk.front();
            stk.pop_front();
        }

        if((int)ans.size()==0){
            ans.push_back('/');
        }

        return ans;
    }
};

// use deque instead of stack so that when you build your answer string you don't have to do ans = "/" + stk.top() + ans
// can iterate over ans in correct order and build string more efficiently
// remember to account for edge cases