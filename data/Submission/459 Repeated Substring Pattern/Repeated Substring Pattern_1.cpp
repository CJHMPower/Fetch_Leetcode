//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 459 Repeated Substring Pattern
// https://leetcode.com//problems/repeated-substring-pattern/description/
// Fetched at 2018-07-24
// Submitted 3 months, 3 weeks ago
// Runtime: 33 ms
// This solution defeats 25.48% cpp solutions

class Solution {
 public:
  bool check(string &s, int i) {
    for (int j = i; j < s.size(); j++) {
      if (s[j] != s[j - i]) {
        return false;
      }
    }
    return true;
  }
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    if (n < 2) {
      return false;
    }
    for (int i = 1; i <= n / 2; i++) {
      if (s[i] == s[0] && n % i == 0) {
        if (check(s, i) == true) {
          return true;
        }
      }
    }
    return false;
  }
};