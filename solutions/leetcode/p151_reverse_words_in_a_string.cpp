class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string curr_word = "";
        for(const char c : s){
            if(c==' '){
                if(curr_word!="") stk.push(curr_word);
                curr_word = "";
            }
            else {
                curr_word += c;
            }
        }
        // push last word -> won't be pushed in loop of no trailing whitespace
        if(curr_word!="") stk.push(curr_word);

        string ans = "";
        while(1){
            ans += stk.top();
            stk.pop();
            if(stk.empty()) break;
            else ans += ' ';
        }

        return ans;
    }
};

// Can be done with O(1) memory by reversing entire string, then reversing each word
// Since it was a LIFO problem, I naturally chose to go with a stack
