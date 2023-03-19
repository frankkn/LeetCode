class WordDictionary {
public:
  struct TrieNode{
    bool isEnd;
    TrieNode* children[26];
    TrieNode(){
      isEnd = false;
      memset(children, 0, sizeof(children));
    }
  };
  TrieNode *root;
    
  WordDictionary() {
    root = new TrieNode();
  }
    
  void addWord(string word) {
    TrieNode* node = root;
    for(auto& c: word){                             
      if(node->children[c-'a'] == 0){
        node->children[c-'a'] = new TrieNode();
      }
      node = node->children[c-'a'];
    }
    node->isEnd = true;
  }
    
  bool search(string word) {
    return dfs(word, 0, root);
  }
    
  bool dfs(string word, int idx, TrieNode* node){
    if(!node)   return false;
    if(idx == word.size())  return node->isEnd;
      
    if(word[idx] == '.'){
      for(int i = 0; i < 26; ++i){
        if(dfs(word, idx+1, node->children[i])){
          return true;
        }
      }
      return false;
    }else{
      if(node->children[word[idx]-'a'] == 0){
        return false;
      }
      node = node->children[word[idx]-'a'];
      return dfs(word, idx+1, node);
    }
  }
};
