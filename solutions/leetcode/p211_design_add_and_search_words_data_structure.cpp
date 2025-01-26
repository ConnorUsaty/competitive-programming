class TrieNode {
private:
    TrieNode* next[26];
    bool is_end;

public:
    TrieNode() {
        for(int i=0; i<26; ++i){
            next[i] = nullptr;
        }
        is_end = false;
    }

    void setEnd() {
        is_end = true;
    }

    bool isEnd() {
        return is_end;
    }

    TrieNode* get(char c){
        return next[c-'a'];
    }

    void put(char c, TrieNode* t){
        next[c-'a'] = t;
    }

    bool contains(char c){
        return next[c-'a'] != nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchFrom(TrieNode* t, string word, int i){
        for(; i<(int)word.length(); ++i){
            char c = word[i];

            if(c=='.'){
                for(int j=0; j<26; ++j){
                    if(t->contains('a'+j)){
                        if (searchFrom(t->get('a'+j), word, i+1)){
                            return true;
                        }
                    }
                }
                return false;
            }
            else {
                if(!t->contains(c)){
                    return false;
                }
                t = t->get(c);
            }
        }

        return t->isEnd();
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* t = root;
        for(const char& c : word){
            if(!t->contains(c)){
                t->put(c, new TrieNode());
            }
            t = t->get(c);
        }
        t->setEnd();
    }
    
    bool search(string word) {
        return searchFrom(root, word, 0);
    }
};

// Trie is good for inserting and searching a database of words especially when there is common prefixes
// also good for lexigraphical ordering

// TrieNode consits of TrieNode* next[26]; and bool is_end;
// Has 5 member functions, isEnd(), setEnd(), contains(), get(), put()
// Can make a Trie out of these TrieNodes and its public member functions
// TrieNode* root of Trie is a dummy root node, no letters stored in it, all stored in the TrieNode* next[26];


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */