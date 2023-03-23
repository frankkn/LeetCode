class Trie {
public:
  struct TrieNode{
    bool isEnd;
    TrieNode *children[26];
    TrieNode(){
      isEnd = false;
      memset(children, 0, sizeof(children));
    }
  };
  
  TrieNode *root;
  
  Trie() {
    root = new TrieNode();
  }
  
  void insert(string word) {
    TrieNode *node = root;
    for(auto& c: word){
      if(node->children[c - 'a'] == 0){
        node->children[c - 'a'] = new TrieNode();
      }
      node = node->children[c - 'a'];
    }
    node->isEnd = true;
  }
  
  bool search(string word) {
    TrieNode *node = root;
    for(auto& c: word){
      if(node->children[c - 'a'] == 0)    return false;
      else{
        node = node->children[c - 'a'];
      }
    }
    return node->isEnd;
  }
  
  bool startsWith(string prefix) {
    TrieNode *node = root;
    for(auto& c: prefix){
      if(node->children[c - 'a'] == 0)    return false;
      else{
        node = node->children[c - 'a'];
      }
    }
    return true;
  }
};