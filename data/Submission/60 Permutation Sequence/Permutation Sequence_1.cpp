//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 60 Permutation Sequence
// https://leetcode.com//problems/permutation-sequence/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  }
  string getPermutation(string &s, int k) {
    if (k == 1) {
      return s;
    }
    int n = s.size();
    string result;
    int len = fact(n - 1);
    int index = (k - 1) % len + 1;
    result = result + s[(k - 1) / len];
    s.erase(s.begin() + (k - 1) / len);
    result = result + getPermutation(s, index);
    return result;
  }
  string getPermutation(int n, int k) {
    string s;
    for (int i = 1; i <= n; i++) {
      s = s + to_string(i);
    }
    return getPermutation(s, k);
  }
};