class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = static_cast<int>(preorder.size());
        std::stack<int> stk;
        int idx = 0;

        while(idx<n && (!stk.empty() || idx==0)) {
            while(idx<n && preorder[idx] == ',') {
                idx++;
            }
            if(idx>=n) break;

            if(preorder[idx] == '#') {
                idx++;
                if(stk.empty()) break;
                // iterate upwards until we find a node thats children still need to be traversed
                while(!stk.empty()) {
                    int t = stk.top();
                    stk.pop();
                    t++;
                    if(t < 3) {
                    stk.push(t);
                    break;
                    }
                }
            } 
            else {
            // we are on a number -> skip over it and push it to stack
            while(idx<n && isdigit(preorder[idx])) idx++;
            stk.push(1);
            }
        }

        return (stk.empty() && idx==n);
    }
};

// watch out for edge cases i.e. "#"
// MAKE SURE TO EXPLICITLY STATE TIME AND SPACE COMPLEXITIES AND TRADE OFFS OF POTENTIAL SOLUTIONS
// MAKE SURE TO TEST YOUR CODE AND WRITE GOOD TEST CASES