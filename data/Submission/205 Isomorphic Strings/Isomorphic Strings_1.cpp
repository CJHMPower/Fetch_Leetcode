//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 205 Isomorphic Strings
// https://leetcode.com//problems/isomorphic-strings/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 52 ms
// This solution defeats 1.96% cpp solutions

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<bool> used(128);
    map<char, char> matches;
    for (int i = 0; i < s.size(); i++) {
      if (matches.find(s[i]) != matches.end()) {
        if (matches[s[i]] != t[i]) {
          return false;
        }
      } else {
        if (used[(int)t[i]] == true) {
          return false;
        }
        matches.insert({s[i], t[i]});
        used[(int)t[i]] = true;
      }
    }
    return true;
  }
};