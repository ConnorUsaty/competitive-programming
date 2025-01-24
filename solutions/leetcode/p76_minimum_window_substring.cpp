class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> cnt_t;
        for(const char& c : t) {
            cnt_t[c]++;
        }
        int missing = (int)cnt_t.size();

        unordered_map<char,int> cnt_s;
        int i=0, j=0, l=0, r=1e9;
        while(i<(int)s.length()){
            cnt_s[s[i]]++;
            if(cnt_s[s[i]] == cnt_t[s[i]]) missing--;
            while(!missing) {
                if(i-j < r-l){
                    l = j;
                    r = i;
                }
                if(cnt_s[s[j]] == cnt_t[s[j]]) missing++;
                cnt_s[s[j]]--;
                j++;
            }
            i++;
        }
        return (r==1e9) ? "" : s.substr(l, r-l+1);
    }
};

// expand window until t included, then shorten window as much as possible while t still in s
// can just keep l and r ptrs and use substr(l, r-l+1) at end
// can do map.size() to get size of maps
// simple sliding window problem, expand window until requirements meet, then decrease window as much as possible while still meeting requirements, keep track of best ans throughout
// changing to unordered_map greatly decreased runtime