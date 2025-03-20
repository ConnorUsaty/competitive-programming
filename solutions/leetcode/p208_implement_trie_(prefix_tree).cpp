class TrieNode{
private:
    TrieNode* next[26];
    bool is_end;

public:
    TrieNode(){
        for(int i=0; i<26; ++i){
            next[i] = nullptr;
        }
        is_end = false;
    }

    TrieNode* get(char c){
        return next[c-'a'];
    }

    void put(char c){
        next[c-'a'] = new TrieNode();
    }

    bool containsKey(char c){
        return (next[c-'a'] != nullptr);
    }

    bool isEnd(){
        return is_end;
    }

    void setEnd(){
        is_end = true;
    }
};


class Trie {
private:
    TrieNode* root;

    TrieNode* searchPrefix(const string& prefix){
        TrieNode* p = root;
        for(const char& c : prefix){
            if(p->containsKey(c)){
                p = p->get(c);
            } else {
                return nullptr;
            }
        }
        return p;
    }

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(const char& c : word){
            if(!p->containsKey(c)){
                p->put(c);
            }
            p = p->get(c);
        }
        p->setEnd();
    }
    
    bool search(string word) {
        TrieNode* res = searchPrefix(word);
        return (res!=nullptr && res->isEnd());
    }
    
    bool startsWith(string prefix) {
        TrieNode* res = searchPrefix(prefix);
        return (res!=nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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