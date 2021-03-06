//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 127 Word Ladder
// https://leetcode.com//problems/word-ladder/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 273 ms
// This solution defeats 34.57% cpp solutions

class Solution {
 public:
  vector<string> findOnedist(string& str, unordered_set<string>& wordList) {
    vector<string> ret;
    for (int i = 0; i < str.size(); i++) {
      char old = str[i];
      for (char c = 'a'; c <= 'z'; c++) {
        str[i] = c;
        if (wordList.find(str) != wordList.end()) {
          ret.push_back(str);
          wordList.erase(str);
        }
      }
      str[i] = old;
    }
    return ret;
  }
  int ladderLength(string beginWord, string endWord,
                   unordered_set<string>& wordList) {
    wordList.insert(endWord);
    queue<string> q;
    q.push(beginWord);
    int len = 0;
    while (!q.empty()) {
      int sz = q.size();
      len++;
      for (int i = 0; i < sz; i++) {
        string str = q.front();
        q.pop();
        if (str == endWord) {
          return len;
        }
        for (auto it : findOnedist(str, wordList)) {
          q.push(it);
        }
      }
    }
    return 0;
  }
};