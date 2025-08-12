struct TrieNode {
    array<TrieNode*, 26> next_{};
    bool end_of_word_ = false;

    TrieNode() {}

    bool exist(char c) {
        return next_[c-'a'] != nullptr;
    }

    TrieNode* get(char c) {
        return next_[c-'a'];
    }

    void put(char c) {
        next_[c-'a'] = new TrieNode();
    }

    bool is_end() {
        return end_of_word_;
    }

    void set_end() {
        end_of_word_ = true;
    }
};

class Trie {
private:
    TrieNode* root_;

public:
    Trie(vector<string>& words) {
        root_ = new TrieNode();
        for(auto& w : words){
            insert(w);
        }
    }

    TrieNode* get_root() {
        return root_;
    }

    void insert(string& s){
        TrieNode* p = root_;
        for(const char & c : s){
            if(p->exist(c)){
                p = p->get(c);
            }
            else{
                p->put(c);
                p = p->get(c);
            }
        }
        p->set_end();
    }
};

class StreamChecker {
private:
    Trie trie_;
    vector<TrieNode*> active_{};
    queue<int> avail_;

public:
    StreamChecker(vector<string>& words) : trie_(words) {}
    
    bool query(char letter) {
        bool flag = false;

        for(int i=0; i<active_.size(); ++i){
            auto& a = active_[i];

            if(a==nullptr) continue;

            if(a->exist(letter)){
                a = a->get(letter);
                flag |= a->is_end();
            }
            else{
                a = nullptr;
                avail_.push(i);
            }
        }

        TrieNode* p = trie_.get_root();
        if(p->exist(letter)){
            p = p->get(letter);
            flag |= p->is_end();
            if (avail_.empty()){
                active_.push_back(p);
            }
            else{
                active_[avail_.front()] = p;
                avail_.pop();
            }
        }

        return flag;
    }
};

// insert all words into trie
// at each char try to move forward all previously valid prefixes
// remove any that fail
// set flag if any are at end
// also create a new entry that is just that char


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */