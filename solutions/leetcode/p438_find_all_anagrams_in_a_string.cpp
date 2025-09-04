class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) {
            return std::vector<int>{};
        }

        std::array<int, 26> p_cnt;
        std::fill(p_cnt.begin(), p_cnt.end(), 0);
        int k = 0;
        for(size_t i=0; i<p.size(); ++i) {
            p_cnt[p[i]-'a']++;
            if(p_cnt[p[i]-'a'] == 1) k++;
        }

        std::array<int, 26> s_cnt;
        std::fill(s_cnt.begin(), s_cnt.end(), 0);
        // init window to size p.size()-1
        for(size_t i=0; i<p.size()-1; ++i) {
            size_t key = s[i]-'a';
            if(++s_cnt[key] == p_cnt[key]) {
                --k;
            }
        }
        // slide window across s
        vector<int> ans;
        for(size_t i=p.size()-1; i<s.size(); ++i) {
            size_t key = s[i]-'a';
            if(++s_cnt[key] == p_cnt[key]) {
                if(--k == 0) {
                    ans.push_back(static_cast<int>(i-p.size()+1));
                }
            }

            key = s[i-p.size()+1]-'a';
            if(--s_cnt[key] == p_cnt[key]-1) {
                ++k;
            }
        }
        return ans;
    }
};

// use std::array when size known at compile time

// use 2 cnt arrays, one for window and one for total p
// build up window to p.size() - 1
// then at each [i] add the element to complete the window
// check if complete window is valid anagram in O(1) -> through k
// remove element at [i-p.size()-1] to make window = p.size()-1 again

// keeping track of k allows us to check if the cnts are equal in O(1)
// rather than iterating over the entire arrays and comparing