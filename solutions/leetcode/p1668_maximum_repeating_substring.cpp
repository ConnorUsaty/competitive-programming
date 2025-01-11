class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans=0, curr=0, i=0;
        while(i<(int)sequence.length()){
            if(sequence.substr(i, word.length()) == word){
                curr++;
                i += word.length();
            }
            else{
                ans=max(ans,curr);
                i -= curr*word.length()-1;
                curr=0;
            }
        }
        return max(ans,curr);
    }
};

// have to backtrack thus -> i -= curr*word.length()-1;
// can use substr(idx, len) to check if the next len chars in sequence match the substr word