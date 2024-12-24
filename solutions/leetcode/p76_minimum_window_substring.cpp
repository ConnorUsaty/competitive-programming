

// min window with cnt1 == cnt2

// expand window keeping track of cnt and ans string until we find a valid answer
// shorten window as much as possible while window remains valid
// when answer no longer valid restart from step 1 (expanding window)
// repeat until gone through entire s, return min len valid ans

// Inititial answer:
// would work except 'A' != 'a'
class Solution {
private:
    bool validWindow(int (&cnt1)[26], int (&cnt2)[26]){
        for(int k=0;k<26;++k){
            if(cnt1[k]>cnt2[k]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int l=0,r=s.length()+1;
        int cnt1[26] = {0};
        int cnt2[26] = {0};

        for(const char& c : t) cnt1[tolower(c)-'a']++;

        int i=0,j=0;
        while(j<s.length()){
            while(!validWindow(cnt1,cnt2) && j<s.length()){
                cnt2[tolower(s[j])-'a']++;
                j++;
            }
            while(validWindow(cnt1,cnt2)){
                if(j-i<r-l){
                    l=i;
                    r=j;
                }
                cnt2[tolower(s[i])-'a']--;
                i++;
            }
        }
        if(r-l==(int)s.length()+1) return "";

        string ans;
        for(int k=l;k<r;++k){
            ans.push_back(s[k]);
        }
        return ans;
    }
};

// min window with cnt1 == cnt2

// expand window keeping track of cnt and ans string until we find a valid answer
// shorten window as much as possible while window remains valid
// when answer no longer valid restart from step 1 (expanding window)
// repeat until gone through entire s, return min len valid ans