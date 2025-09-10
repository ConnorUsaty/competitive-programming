class Encrypter {
private:
    unordered_map<char,string> enc_mp;
    unordered_map<string,int> dec_mp;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0; i<keys.size(); ++i) {
            enc_mp.insert({keys[i], values[i]});
        }
        for(const std::string & s : dictionary) {
            dec_mp[encrypt(s)]++;
        }
    }
    
    string encrypt(string word1) {
        string s{};
        for(const char & c : word1) {
            if(enc_mp.find(c) == enc_mp.end()) return "";
            s += enc_mp[c];
        }
        return s;
    }
    
    int decrypt(string word2) {
        return dec_mp[word2];
    }
};

// most likely meant to be done with trie pruning

// with curr impl:
// O(n) time and space for init
// O(n) time, O(1) space for encrypt
// O(1) time, O(1) space for decrypt

// string[i] = values[j] where keys[j] == c (orig string[i])
// iff string[i] NOT in kets, return ""

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */