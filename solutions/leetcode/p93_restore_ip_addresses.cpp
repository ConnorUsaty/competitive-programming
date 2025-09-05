class Solution {
private:
    void backtrack(vector<string>& ans, string& curr, int sec, int curr_val, string& s, size_t idx) {
        if(idx == s.size() && sec==4) {
            ans.push_back(curr);
            return;
        }
        // at start of each sec make sure its possible to finish address
        if(curr_val==0) {
            int rem = s.size()-idx;
            int rem_sec = 4-sec+1;
            if(rem < rem_sec || rem > 3*rem_sec) return;
        }

        // make sure value is within range
        int new_val = curr_val;
        new_val *= 10;
        new_val += s[idx]-'0';
        if(new_val<0 || new_val>255) return;

        // dont add trailing '.'
        if(idx==s.size()-1) {
            curr.push_back(s[idx]);
            backtrack(ans, curr, sec, 0, s, idx+1);
            curr.pop_back();
            return;
        }

        // can not have leading '0'
        if(curr_val==0 && s[idx]=='0') {
            curr.push_back(s[idx]);
            curr.push_back('.');
            backtrack(ans, curr, sec+1, 0, s, idx+1);
            curr.pop_back();
            curr.pop_back();
        }
        else {
            // anything else try both possibilites
            curr.push_back(s[idx]);
            backtrack(ans, curr, sec, new_val, s, idx+1);
            curr.push_back('.');
            backtrack(ans, curr, sec+1, 0, s, idx+1);
            curr.pop_back();
            curr.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        const size_t n = s.size();
        if (n<4 || n>12) return std::vector<std::string>{};

        vector<string> ans;
        string curr = "";
        backtrack(ans, curr, 1, 0, s, 0);
        return ans;
    }
};