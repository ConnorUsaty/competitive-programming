class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(char c:word1)
            w1[c-'a']++,w3[c-'a'] = 1;
    
        for(char c:word2)
            w2[c-'a']++,w4[c-'a'] = 1;
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&w3==w4;
    }
};

// need to check if they contain the same letters and the same frequencies, BUT the frequencies for each letter do not have to match
// when counting letters use an array with 26 indexes for most efficient implementation
// solution is still O(n) despite using sort because we are sorting an array of constant length -> 26log(26) = O(1)