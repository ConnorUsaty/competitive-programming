class Solution {
private:
    int isVowel(char c){
        return(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

public:
    int maxVowels(string s, int k) {
        int cnt=0, ans=0;
        for(int i=0;i<k;i++) ans+=isVowel(s[i]);
        cnt = ans;

        for(int i=1;i<s.length()-k+1;++i){
            cnt += isVowel(s[i+k-1]) - isVowel(s[i-1]);
            ans = max(ans, cnt);
        }

        return ans;
    }
};


// sliding window
// initialize curr and ans variables to starting window value in init loop
// then slide over array in second loop keeping track of the curr cnt while checking if you found a new max in each window

// O(n) time, O(1) space