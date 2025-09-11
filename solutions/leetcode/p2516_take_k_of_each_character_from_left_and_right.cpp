class Solution {
public:
    int takeCharacters(string s, int k) {
        const int n = (int)s.size();

        std::array<int, 3> cnt;
        std::fill(cnt.begin(), cnt.end(), 0);
        for(int i=0; i<n; ++i) {
            cnt[s[i]-'a']++;
        }
        for(int i=0; i<3; ++i) {
            if(cnt[i]<k) return -1;
        }

        int l=0, mx=0;
        for(int r=0; r<n; ++r) {
            // increase window size
            cnt[s[r]-'a']--;

            // decrease window until valid
            while(cnt[s[r]-'a'] < k) {
                cnt[s[l]-'a']++;
                l++;
            }
            // window is valid, update mx window size
            mx = max(mx, r-l+1);
        }
        return n - mx;
    }
};

// sliding window
// O(n) time
// O(1) space

// for many problems where we can only choose from the l or r side
// we can apply sliding window

// we slide through the middle and check if some attribute still applies
// to all elements OUTSIDE the window -> thus checking if we can get there by
// choosing that many times from left and right