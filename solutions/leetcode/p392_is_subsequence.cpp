class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i=0, t_i=0;

        while(s_i<s.length() && t_i<t.length()){
            if (s[s_i]==t[t_i]){
                s_i++;
                t_i++;
            }
            else {
                t_i++;
            }
        }
        return s_i==s.length();
    }
};

// Just move two pointers along and check if we are able to move across s fully
// Easier version of longest subsequnce which follows same logic but with DP