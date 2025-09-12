class Solution {
private:
    // check ops req to make all b < a
    int check_ops_req(std::array<int,26>& cnt_a, std::array<int,26>& cnt_b) {
        std::array<int,27> s_cnt;
        std::fill(s_cnt.begin(), s_cnt.end(), 0);
        for(int i=25; i>=0; --i) {
            s_cnt[i] = s_cnt[i+1] + cnt_b[i];
        }
        s_cnt[26] = s_cnt[25];

        int p_cnt = 0;
        int ops = INT_MAX;
        for(int i=0; i<26; ++i) {
            p_cnt += cnt_a[i];
            ops = min(ops, p_cnt + s_cnt[i+1]);
        }
        return ops;
    }

public:
    int minCharacters(string a, string b) {
        std::array<int, 26> cnt_a;
        std::fill(cnt_a.begin(), cnt_a.end(), 0);
        for(const char & c : a) {
            cnt_a[c-'a']++;
        }
        std::array<int, 26> cnt_b;
        std::fill(cnt_b.begin(), cnt_b.end(), 0);
        for(const char & c : b) {
            cnt_b[c-'a']++;
        }

        // check b < a and b < a
        int ans = min(check_ops_req(cnt_a, cnt_b), check_ops_req(cnt_b, cnt_a));

        // check a == b, all one distinct letter
        int mx = 0;
        int total = 0;
        for(int i=0; i<26; ++i) {
            mx = max(mx, cnt_a[i]+cnt_b[i]);
            total += cnt_a[i] + cnt_b[i];
        }
        ans = min(ans, total-mx);
        return ans;
    }
};

// we can represent each string by its cnt
// this allows us to quickly iterate over it in O(26) rather than O(n)

// consist of lowercase letters

// in one op change any char to any lowercase char

// satisfy ONE of three conds

// return MIN ops req


// check for all 3, one at a time and return mn
// to do a < b
// get count, if cnt[mx[a]] > cnt[mn[b]] move mx[a] down else move mn[b] up
// to do b < a, just do opposite of above
// to check a == b
// try every letter ? O(26 * 26 * 2) 