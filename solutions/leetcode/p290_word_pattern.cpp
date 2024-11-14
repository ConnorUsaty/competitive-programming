class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> h;
        map<string,char> h2;

        // extract words into vector using ' ' as delimiter
        vector<string> p;
        string curr_word = "";
        for (int i=0;i<s.length();++i){
            if (s[i]==' ') {
                p.push_back(curr_word);
                curr_word = "";
            }
            else {
                curr_word.push_back(s[i]);
            }
        }
        p.push_back(curr_word);

        if(p.size()!=pattern.length()) return false;

        // make sure pattern[i] has not been used already by a diff word and vice versa
        // need to check both or WA
        for (int i=0;i<pattern.length();++i){
            if(h.find(pattern[i]) != h.end() && h[pattern[i]] != p[i]){
                return false;
            }
            if(h2.find(p[i]) != h2.end() && h2[p[i]] != pattern[i]){
                return false;
            }
            h[pattern[i]] = p[i];
            h2[p[i]] = pattern[i];
        }
        return true;
    }
};