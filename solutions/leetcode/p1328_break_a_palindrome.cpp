class Solution {
public:
    string breakPalindrome(string palindrome) {
        const size_t n = palindrome.size();
        if(n == 1) return "";

        for(size_t i=0; i<n; ++i) {
            if(palindrome[i] != 'a' && (!(n&1) || i!=n/2)) {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};