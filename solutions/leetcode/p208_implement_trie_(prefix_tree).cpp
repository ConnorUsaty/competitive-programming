class TrieNode {
private:
    TrieNode* next[26];
    bool is_end;

public:

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
        is_end = false;
    }

    bool containsKey(char c) {
        return next[c-'a'] != nullptr;
    }

    TrieNode* get(char c){
        return next[c-'a'];
    }

    void put(TrieNode* t, char c){
        next[c-'a'] = t;
    }

    void setEnd() {
        is_end = true;
    }

    bool isEnd() {
        return is_end;
    }
};


class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    // O(m) time, m = length of word, O(m) space, worst case all char in word require new node
    void insert(string word) {
        TrieNode* t = root;
        for(const char& c : word){
            if(!t->containsKey(c)){
                TrieNode* new_node = new TrieNode();
                t->put(new_node, c);
            }
            t = t->get(c);
        }
        t->setEnd();
    }
    
    // O(m) time, O(1) space
    bool search(string word) {
        TrieNode* t = root;
        for(const char& c : word){
            if(!t->containsKey(c)){
                return false;
            }
            t = t->get(c);
        }
        return t->isEnd();
    }
    
    // O(m) time, O(1) space
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for(const char& c : prefix){
            if(!t->containsKey(c)){
                return false;
            }
            t = t->get(c);
        }
        return true;
    }
};

// TrieNode consists of TrieNode* next[26]; and bool is_end;
// contains methods, containsKey(), put(), get(), isEnd(), setEnd()
// Trie consists of TrieNode* root;
// contains insert(), search(), searchPrefix(), which are implemented with TrieNode and its public methods

// root is dummy node, all letters are in the links or next

// very efficient data structure for large datasets of words especially with common prefixes

// can be used for solving words games, autocomplete, spell checker, etc.


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */