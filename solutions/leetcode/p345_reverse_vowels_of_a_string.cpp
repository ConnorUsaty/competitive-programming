class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    
public:
    string reverseVowels(string s) {
        // two pointer find vowels and switch similar to quick sort partitioning
        int l=0, r=s.length()-1;
        while(l<r){
            if(!(isVowel(s[l]))) l++;
            else if(!(isVowel(s[r]))) r--;
            else{
                // both vowels -> swap and in/decrement ptrs
                swap(s[l++],s[r--]);
            }
        }
        return s;
    }
};

// for all two pointer problems where we are doing specific swaps / reverses we can use two pointers and then swap when we find valid swapping elements similar to quick sort
// tolower(c) returns the char in lowercase in c++