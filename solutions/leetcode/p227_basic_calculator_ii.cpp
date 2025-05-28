class Solution {
public:
    int calculate(string s) {
        stack<long long> num_stack;
        stack<char> op_stack;

        auto get_num = [&s](int& i){
            while(i<s.size() && s[i]==' '){
                i++;
            }
            int n=0;
            while(i<s.size() && isdigit(s[i])){
                n *= 10;
                n += s[i]-48;
                i++;
            }
            return n;
        };

        for(int i=0; i<static_cast<int>(s.size()); ++i){
            if(s[i]==' ') continue;

            if(isdigit(s[i])){
                num_stack.push(get_num(i));
                --i;
            }
            else{
                if(s[i]=='*'){
                    int x = num_stack.top(); num_stack.pop();
                    int y = get_num(++i);
                    --i;
                    num_stack.push(x*y);
                }
                else if(s[i]=='/'){
                    int x = num_stack.top(); num_stack.pop();
                    int y = get_num(++i);
                    --i;
                    num_stack.push(y==0 ? 0 : x/y);
                }
                else if(!op_stack.empty()){
                    char op = op_stack.top(); op_stack.pop();
                    int y = num_stack.top(); num_stack.pop();
                    int x = num_stack.top(); num_stack.pop();
                    if(op=='+'){
                        num_stack.push(x+y);
                    }
                    else{
                        num_stack.push(x-y);
                    }
                    op_stack.push(s[i]);
                }
                else{
                    op_stack.push(s[i]);
                }
            }
        }

        while(!op_stack.empty()){
            char op = op_stack.top(); op_stack.pop();
            int y = num_stack.top(); num_stack.pop();
            int x = num_stack.top(); num_stack.pop();
            if(op=='+'){
                num_stack.push(x+y);
            }
            else{
                num_stack.push(x-y);
            }
        }

        return num_stack.top();
    }
};


// most of the calculator questions can be solved using stacks to implement BEDMAS (order of operations)
// hardest part is figuring out how to correctly do that
// a common optimization for stack questions is O(1) space
// when you ONLY interact with the last item and never have to "unwind" the stack you can just store the last item in a variable making for O(1) space