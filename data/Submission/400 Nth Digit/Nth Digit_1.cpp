//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 400 Nth Digit
// https://leetcode.com//problems/nth-digit/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  int findNthDigit(int n) {
    if (n < 10) {
      return n;
    }
    int m = 1;
    int sum = 0;
    while (sum + 9 * m * pow(10, m - 1) < n) {
      sum += 9 * m * pow(10, m - 1);
      m++;
    }
    int d = (n - sum - 1) / m;
    int r = (n - sum - 1) % m + 1;
    int digit = pow(10, m - 1) + d;
    digit /= pow(10, m - r);
    return digit % 10;
  }
};