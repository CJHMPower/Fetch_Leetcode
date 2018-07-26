//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 208 Implement Trie (Prefix Tree)
// https://leetcode.com//problems/implement-trie-(prefix-tree)/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 61 ms
// This solution defeats 12.08% cpp solutions

class TrieNode {
 public:
  // Initialize your data structure here.
  TrieNode() : end(false) {
    for (int i = 0; i < Size; i++) {
      children[i] = nullptr;
    }
  }
  static const int Size = 26;
  bool end;
  TrieNode* children[Size];
};
class Trie {
 public:
  Trie() { root = new TrieNode(); }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode* cur = root;
    int i = 0;
    while (i < word.size() && cur->children[word[i] - 'a'] != nullptr) {
      cur = cur->children[word[i] - 'a'];
      i++;
    }
    if (i >= word.size()) {
      cur->end = true;
      return;
    }
    while (i < word.size()) {
      cur->children[word[i] - 'a'] = new TrieNode();
      cur = cur->children[word[i] - 'a'];
      i++;
    }
    cur->end = true;
  }
  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode* cur = root;
    for (int i = 0; i < word.size(); i++) {
      if (cur->children[word[i] - 'a'] == nullptr) {
        return false;
      }
      cur = cur->children[word[i] - 'a'];
    }
    return cur->end;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode* cur = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (cur->children[prefix[i] - 'a'] == nullptr) {
        return false;
      }
      cur = cur->children[prefix[i] - 'a'];
    }
    return true;
  }

 private:
  TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");