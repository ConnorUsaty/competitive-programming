class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman_to_int = {{'I',1},{'V',5},{'X',10},{'L',50},
                                                {'C',100},{'D',500},{'M',1000}};

        int prev=0, ans=0;
        for(const char& c : s){
            int curr = roman_to_int[c];
            ans += curr;
            if(prev<curr) {
                ans -= 2*prev;
            }
            prev = curr;
        }
        return ans;
    }
};

// If prev element < curr, you have to -2*prev, once for previous addition, once for deduction to current symbol