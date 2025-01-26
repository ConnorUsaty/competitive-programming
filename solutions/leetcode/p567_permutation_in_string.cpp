class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt1[26] = {0};
        int cnt2[26] = {0};

        for(const char& c : s1) cnt1[c-'a']++;

        int i=0,j=0;
        while(j<s2.length()){
            while(j-i < s1.length() && j<s2.length()){
                cnt2[s2[j]-'a']++;
                j++;
            }
            
            bool match = true;
            for(int k=0;k<26;++k){
                if(cnt1[k]!=cnt2[k]){
                    match = false;
                    break;
                }
            }
            if(match) return true;

            cnt2[s2[i]-'a']--;
            i++;
        }
        return false;
    }
};

// if the cnt in the window is the same as the total count of the substring, then this is a permutation
// if the counts match the same word can be made by rearranging letters, therefore permutation

// used int cnt[26] = {0} for optimized counting of specific characters, i.e. upper or lower english chars only
// need to check cnt of each char (all 26 indexes) seperately in c++, cannot do cnt1 == cnt2

// build window up to correct size by incrementing j, then increment i to shorten / slide window as necessary
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        
        vector<int> cnt1(26, 0);
        for(const char& c : s1) cnt1[c-'a']++;

        vector<int> cnt2(26, 0);
        for(int i=0; i<s1.length(); ++i) cnt2[s2[i]-'a']++;
        if(cnt1 == cnt2) return true;

        int j=0;
        for(int i=s1.length(); i<s2.length(); ++i){
            cnt2[s2[j]-'a']--;
            cnt2[s2[i]-'a']++;
            if(cnt1 == cnt2) return true;
            j++;
        }
        return false;
    }
};

// since this sliding window has a fixed size, makes more sense to build it up to size seperately, then just slide it along in loop
// for a window without fixed size (any problem where you are changing window size, i.e. trying to find biggest / smallest window that meets certain requirement)
// use one bigger while loop to slide window across while increasing and decreasing window size as necessary
// normally would increase window as much as needed until requirement met, then decrease as much as possible while still meeting requirement

// expand window to length of s1
// then slide window across s2 checking if the counts are the same at any point
// if the counts are the same then permutation and return true
// lowercase only so we can use array

// when using vector<int> you can directly do cnt1 == cnt2, as they have built in comparators
// when using int [], (normal static array), you CANNOT do cnt1 == cnt2, have to write own helper to check
