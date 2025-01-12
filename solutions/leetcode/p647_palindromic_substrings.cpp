class Solution {
private:
    int count(int i, int j, const string s){
        int ans = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
            ans++;
        }
        return ans;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); ++i){
            ans += count(i, i, s);
            ans += count(i, i+1, s);
        }
        return ans;
    }
};

// very similar to longest palindromic substring, expand from each index treating it as the center of a potential palindrome
// check for each index as an even and an odd center
// be careful about substring vs subsequence, BIG DIFFERENCE