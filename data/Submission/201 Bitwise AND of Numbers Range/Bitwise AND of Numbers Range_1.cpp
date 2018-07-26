//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 201 Bitwise AND of Numbers Range
// https://leetcode.com//problems/bitwise-and-of-numbers-range/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 68 ms
// This solution defeats 3.31% cpp solutions

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    for (int k = 0; m > 0 && n > 0; k++) {
      if (m == n) {
        while (k > 0) {
          m = m << 1;
          k--;
        }
        return m;
      }
      m = m >> 1;
      n = n >> 1;
    }
    return 0;
  }
};