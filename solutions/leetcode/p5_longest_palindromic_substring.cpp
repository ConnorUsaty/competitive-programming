class Solution {
private:
    string check(int i, int j, string s){
        while(i>=0 && j<s.length()){
            if(s[i]==s[j]){
                i--;
                j++;
            } else {
                break;
            }
        }
        return s.substr(i+1, j-i-1);
    }

public:
    string longestPalindrome(string s) {
        int n = (int) s.length();
        string ans;
        for(int i=0; i<n; ++i){
            string odd = check(i, i, s);
            string even = check(i, i+1, s);
            if(odd.length()>ans.length()){
                ans = odd;
            }
            if(even.length()>ans.length()){
                ans = even;
            }
        }
        return ans;
    }
};

// can expand from each index treating it as a potential center for the palindrome
// O(n^2) time, O(1) space