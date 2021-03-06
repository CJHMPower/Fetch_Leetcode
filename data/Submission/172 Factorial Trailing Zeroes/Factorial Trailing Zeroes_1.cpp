//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 172 Factorial Trailing Zeroes
// https://leetcode.com//problems/factorial-trailing-zeroes/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int trailingZeroes(int n) {
    int count = 0;
    while (n) {
      count += (n / 5);
      n /= 5;
    }
    return count;
  }
};