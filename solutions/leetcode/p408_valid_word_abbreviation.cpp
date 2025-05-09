class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0, j=0;
        while(i<(int)word.size() && j<(int)abbr.size()){
            if(isdigit(abbr[j])){
                if(abbr[j]=='0') return false;
                int n=0;
                while(isdigit(abbr[j])){
                    n *= 10;
                    n += abbr[j]-'0';
                    j++;
                }
                i += n;
            }
            else{
                if(word[i]==abbr[j]){
                    i++;
                    j++;
                }else{
                    return false;
                }
            }
        }
        return (i==(int)word.size() && j==(int)abbr.size());
    }
};