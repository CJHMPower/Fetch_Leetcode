//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 647 Palindromic Substrings
// https://leetcode.com//problems/palindromic-substrings/description/
// Fetched at 2018-07-24
// Submitted 5 months ago
// Runtime: 20 ms
// This solution defeats 19.99% cpp solutions

class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.size();
    int ret = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int k = 0; k < n; k++) {
      for (int i = 0; i + k < n; i++) {
        if (k < 2) {
          dp[i][i + k] = (s[i] == s[i + k]);
        } else {
          dp[i][i + k] = (dp[i + 1][i + k - 1]) && (s[i] == s[i + k]);
        }
        if (dp[i][i + k] == true) {
          ret++;
        }
      }
    }
    return ret;
  }
};