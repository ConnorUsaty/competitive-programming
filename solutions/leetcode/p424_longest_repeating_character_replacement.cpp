class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0,mx=0,ans=-1;
        int cnt[26] = {0};

        while(j<n){
            ++cnt[s[j]-'A'];
            mx = max(mx, cnt[s[j]-'A']);
            if((j-i+1)-mx > k){
                // elements not replacable by k
                --cnt[s[i]-'A'];
                ++i;
            }
            ans = max(ans, (j-i+1));
            ++j;
        }
        return ans;
    }
};


// use cnt arr instead of mp or vec for better space / time when counting specific set of characters
// increase window as big as possible, then slide window over when the k cannot be used to continue sequence
// int cnt[26] = {0}; initialzes an array of size 26 of ints to 0