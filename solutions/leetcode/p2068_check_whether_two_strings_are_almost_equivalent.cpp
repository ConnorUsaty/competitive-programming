class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt1[26] = {0};
        for(const char& c : word1) cnt1[c-'a']++;
        int cnt2[26] = {0};
        for(const char& c : word2) cnt2[c-'a']++;

        for(int i=0; i<26; ++i){
            if(abs(cnt1[i]-cnt2[i])>3) return false;
        }
        return true;
    }
};