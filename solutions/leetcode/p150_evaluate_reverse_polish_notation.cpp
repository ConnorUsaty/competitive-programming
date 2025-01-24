class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        string ops = "+-*/";
        for(const string& s : tokens) {
            if(ops.find(s)==string::npos){
                stk.push(stoi(s));
                continue;
            }

            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            int res;

            if(s == "+") {
                res = y+x;
            }
            else if(s == "-") {
                res = y-x;
            }
            else if(s == "*") {
                res = y*x;
            }
            else if(s == "/") {
                res = y/x;
            }
            stk.push(res);
        }
        return stk.top();
    }
};

// can use stoi() to convert string to int
// str.find(x) returns string::npos if x not in str