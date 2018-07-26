//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 343 Integer Break
// https://leetcode.com//problems/integer-break/description/
// Fetched at 2018-07-24
// Submitted 2 years, 2 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int *p = new int[n + 1];
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    for (int i = 4; i < n + 1; i++) {
      int max = 0;
      for (int k = 1; k < i; k++) {
        if (p[k] * p[i - k] > max) max = p[k] * p[i - k];
      }
      p[i] = max;
    }
    int result = p[n];
    delete[] p;
    return result;
  }
};