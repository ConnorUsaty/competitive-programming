class Solution {
public:
    string robotWithString(string s) {
        const int n = (int)s.size();

        std::array<int, 26> last;
        std::fill(last.begin(), last.end(), -1);
        for(int i=0; i<n; ++i) {
            last[s[i]-'a'] = i;
        }

        stack<char> t;
        string ans{};
        int mn = 0, i = 0;
        while(i < n) {
            while(last[mn]<i && (t.empty() || t.top() != mn+'a')) {
                mn++;
            }
            if(!t.empty() && t.top()<=mn+'a') {
                while(!t.empty() && t.top()<=mn+'a') {
                    ans += t.top();
                    t.pop();
                }
            }
            else {
                if(s[i] == mn+'a') {
                    ans += s[i];
                } else {
                    t.push(s[i]);
                }
                i++;
            }
        }
        while(!t.empty()) {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};

// O(n) time add each char to ans and t once, O(n) space for t

// we can always place all of the next lexicographically smallest chars
// as long as they are still present in s
// OR if they are on the back of t
// keep doing this until s empty then add on t in reverse