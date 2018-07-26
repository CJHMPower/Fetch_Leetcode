//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 93 Restore IP Addresses
// https://leetcode.com//problems/restore-ip-addresses/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 9.13% cpp solutions

class Solution {
 public:
  bool isvalid(string s) {
    if (s.size() > 1 && s[0] == '0') {
      return false;
    }
    int reg = stoi(s);
    return reg >= 0 && reg <= 255;
  }
  void helper(string s, int idx, vector<string>& res, string curSol,
              int point) {
    if (point >= 4) {
      if (idx == s.size()) res.push_back(curSol);
      return;
    }
    if (idx >= s.size())  // illegal index
      return;
    int restLen = s.size() - idx;
    for (int i = 1; i <= restLen && i <= 3; i++) {
      string str = s.substr(idx, i);
      if (isvalid(str)) {
        string newSol = curSol;
        if (newSol == "")
          newSol += str;
        else
          newSol = newSol + "." + str;
        helper(s, idx + i, res, newSol, point + 1);
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.size() < 4) {
      return result;
    }
    helper(s, 0, result, "", 0);
    return result;
  }
};