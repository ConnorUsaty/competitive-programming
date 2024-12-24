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
