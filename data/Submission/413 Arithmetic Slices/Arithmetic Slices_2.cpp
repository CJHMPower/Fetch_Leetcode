//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 413 Arithmetic Slices
// https://leetcode.com//problems/arithmetic-slices/description/
// Fetched at 2018-07-24
// Submitted 5 months ago
// Runtime: 181 ms

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    if (A.empty()) {
      return 0;
    }
    int n = A.size();
    int ret = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n - 1; i++) {
      dp[i][i] = true;
      dp[i][i + 1] = true;
    }
    dp[n - 1][n - 1] = true;
    for (int k = 2; k <= n; k++) {
      for (int i = 0; i + k < n; i++) {
        dp[i][i + k] = dp[i][i + k - 1] &&
                       (A[i + k] - A[i + k - 1] == A[i + k - 1] - A[i + k - 2]);
        if (dp[i][i + k] == true) {
          ret++;
        }
      }
    }
    return ret;
  }
};