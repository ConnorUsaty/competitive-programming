class Trie {
private:
    struct TrieNode {
        bool is_end_{false};
        unordered_map<string,TrieNode*> next_{};

        void set_end() {
            is_end_ = true;
        }

        bool is_end() {
            return is_end_;
        }

        bool exist(std::string& s) {
            return next_.find(s) != next_.end();
        }

        void put(std::string& s) {
            TrieNode* t = new TrieNode;
            next_.insert({s, t});
        }

        TrieNode* get(std::string& s) {
            return next_[s];
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode;
    }

    void insert(const std::string& s) {
        size_t idx = 0;
        TrieNode* p = root;
        while(idx < s.size()) {
            string curr = "";
            while(idx < s.size() && s[idx]!='/' ) {
                curr += s[idx];
                idx++;
            }
            if(curr!="") {
                if(!p->exist(curr)) {
                    p->put(curr);
                }
                p = p->get(curr);
            }
            idx++;
        }
        p->set_end();
    }

    bool check_prefix(const std::string& s) {
        size_t idx = 0;
        TrieNode* p = root;
        while(idx < s.size()) {
            string curr = "";
            while(idx < s.size() && s[idx]!='/' ) {
                curr += s[idx];
                idx++;
            }
            if(curr!="" && idx<s.size()) {
                p = p->get(curr);
                if(p->is_end()) return true;
            }
            idx++;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie t;
        for(const std::string& s : folder) {
            t.insert(s);
        }
        std::vector<std::string> ans;
        for(const std::string& s : folder) {
            if(!t.check_prefix(s)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};