struct TrieNode {
    std::array<TrieNode*, 26> next_;
    std::string word_{};
    // int cnt_{0};

    TrieNode() {
        std::fill(next_.begin(), next_.end(), nullptr);
    }

    TrieNode* get(char c) {
        return next_[c-'a'];
    }

    void put(char c) {
        next_[c-'a'] = new TrieNode();
    }

    bool exist(char c) {
        return next_[c-'a'] != nullptr;
    }

    bool is_leaf() {
        for(int i=0; i<26; ++i) {
            if(next_[i] != nullptr) return false;
        }
        return true;
    }
};

class Trie {
private:
    TrieNode* root_;

public:
    Trie() {
        root_ = new TrieNode();
    }

    void insert(const std::string& s) {
        TrieNode* p = root_;
        for(const char& c : s) {
            if(!p->exist(c)) {
                p->put(c);
            }
            p = p->get(c);
            // p->cnt_++;
        }
        p->word_ = s;
    }

    TrieNode* get_root() const noexcept {
        return root_;
    }
};

class Solution {
private:
    void dfs(TrieNode* parent, vector<vector<char>>& board, int i, int j, set<pair<int,int>>& vis, vector<string>& ans) {
        // int deletions = 0;
        char letter = board[i][j];
        TrieNode* child = parent->get(letter);
        if(child->word_ != "") {
            ans.push_back(child->word_);
            child->word_ = "";
            // child->cnt_--;
            // deletions++;
        }

        const vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto& [di, dj] : directions) {
            int ni = i + di;
            int nj = j + dj;
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size() && vis.insert({ni, nj}).second) {
                if(child->exist(board[ni][nj])) {
                    dfs(child, board, ni, nj, vis, ans);
                }
                vis.erase({ni, nj});
            }
        }

        // prune child if possible
        if(child->is_leaf()) {
            parent->next_[letter-'a'] = nullptr;
            delete child;
        }
        // prune parent if possible
        // parent->cnt_ -= deletions;
        // return deletions;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());

        Trie t;
        for(const std::string& s : words) {
            t.insert(s);
        }

        std::vector<std::string> ans;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                TrieNode* p = t.get_root();
                if(p->exist(board[i][j])) {
                    set<pair<int,int>> vis;
                    vis.insert({i, j});
                    dfs(p, board, i, j, vis, ans);
                }
            }
        }

        return ans;
    }
};

// trie
// insert all words
// loop over board start dfs from each pos
// at each pos check if we can extend any of our existing connections

// use PARENT NODE as dfs param to prune trie
// reset state before returning -> mandatory for backtracking
// modify input arr to mark as visited in place and save mem
// also using vector<vector<int>> visited when we had an exact m x n board would be much more efficient