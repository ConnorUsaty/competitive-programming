class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, i=0, j=0, n=(int)s.size();
        unordered_map<char,int> cnt;
        while(i<n){
            cnt[s[i]]++;
            while(cnt[s[i]]>=2){
                // remove repeat
                cnt[s[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};

// window / subarray / substring / contiguous subset -> SLIDING WINDOW

// expand window as much as possible while all char unique
// once repeat found, decrease window until valid again
// ans is max of all valid windows
