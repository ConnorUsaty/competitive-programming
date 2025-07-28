struct TrieNode {
  std::vector<TrieNode*> next;
  std::vector<std::string> products;

  TrieNode() : next(26, nullptr) {}

  void add_product(std::string product){
    products.push_back(product);
  }

  std::vector<std::string> query(){
    std::vector<std::string> res;
    for(int i=0; i < min(3, (int)products.size()); ++i){
      res.push_back(products[i]);
    }
    return res;
  }

  TrieNode* get(char c){
    return next[c-'a'];
  }

  bool exist(char c){
    return get(c) != nullptr;
  }

  void put(char c){
    next[c-'a'] = new TrieNode();
  }
};

class Trie {
private:
  TrieNode* root;

public:
  Trie() {
    root = new TrieNode();
  }

  void insert(std::string word){
    TrieNode* p = root;
    for(const char & c : word){
      if(!p->exist(c)){
        p->put(c);
      }
      p = p->get(c);
      p->add_product(word);
    }
  }

  std::vector<std::vector<std::string>> search(std::string word){
    std::vector<std::vector<std::string>> ans;
    TrieNode* p = root;
    for(const char & c : word){
      if(!p || !p->exist(c)){
        p = nullptr;
        ans.push_back(std::vector<std::string>{});
        continue;
      }
      p = p->get(c);
      ans.push_back(p->query());
    }
    return ans;
  }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        Trie trie;
        for(auto& p : products){
            trie.insert(p);
        }
        return trie.search(searchWord);
    }
};