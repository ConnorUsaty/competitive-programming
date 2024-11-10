class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        if (pos != string::npos) {
            return pos;
        }
        else {
            return -1;
        }
    }
};

// Can call find() -> O(nm) worst case
// Can use KMP -> O(n+m) worst case, where n = length of str, m = length of substr