//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 375 Guess Number Higher or Lower II
// https://leetcode.com//problems/guess-number-higher-or-lower-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 84 ms
// This solution defeats 3.75% cpp solutions

class Solution {
 public:
  int DP(vector<vector<int>>& dp, int left, int right) {
    if (left >= right) {
      return 0;
    }
    if (dp[left][right] != 0) {
      return dp[left][right];
    }
    int res = INT_MAX;
    for (int x = left; x <= right; x++) {
      res = min(res, x + max(DP(dp, left, x - 1), DP(dp, x + 1, right)));
    }
    dp[left][right] = res;
    return res;
  }
  int getMoneyAmount(int n) {
    if (n == 1) {
      return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    return DP(dp, 1, n);
  }
};