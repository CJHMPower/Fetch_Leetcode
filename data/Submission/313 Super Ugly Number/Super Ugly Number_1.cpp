//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 313 Super Ugly Number
// https://leetcode.com//problems/super-ugly-number/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 116 ms
// This solution defeats 13.89% cpp solutions

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n == 1) {
      return 1;
    }
    vector<int> index(primes.size(), 1);
    int m = primes.size();
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    int sel = INT_MAX;
    int idx = 0;
    for (int i = 2; i <= n; i++) {
      sel = INT_MAX;
      for (int j = 0; j < m; j++) {
        sel = min(sel, dp[index[j]] * primes[j]);
      }
      for (int j = 0; j < m; j++) {
        if (sel == dp[index[j]] * primes[j]) {
          dp[i] = dp[index[j]] * primes[j];
          index[j]++;
        }
      }
    }
    return dp[n];
  }
};