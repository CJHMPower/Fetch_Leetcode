//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 22 Generate Parentheses
// https://leetcode.com//problems/generate-parentheses/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 12.4% cpp solutions

class Solution {
 public:
  void search(int left, int right, string path, vector<string>& v) {
    if (left == 0 && right == 0) {
      v.push_back(path);
      return;
    }
    if (left > 0) {
      search(left - 1, right, path + "(", v);
    }
    if (right > left) {
      search(left, right - 1, path + ")", v);
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> v;
    search(n, n, "", v);
    return v;
  }
};