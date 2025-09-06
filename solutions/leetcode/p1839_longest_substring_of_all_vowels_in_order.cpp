class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowels = "aeiou";
        int j=0, i=0, l=0, ans=0;
        while(i<word.size()){
            if(word[i]!=vowels[j]){
                j=0;
            }
            while(i<word.size() && word[i]!=vowels[j]) {
                i++;
            }
            if(i<word.size() && word[i]==vowels[j] && j==0) {
                l=i;
            }
            while(i<word.size() && word[i]==vowels[j]){
                i++;
            }
            if(word[i-1]==vowels[j]){
                if(++j==vowels.size()){
                    ans = max(ans, i-l);
                    j=0;
                }
            }
        }
        return ans;
    }
};