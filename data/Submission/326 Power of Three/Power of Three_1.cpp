//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 326 Power of Three
// https://leetcode.com//problems/power-of-three/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 225 ms

class Solution {
 public:
  int integer(double s) {
    int down = int(s);
    int up = down + 1;
    if (fabs(down - s) < fabs(up - s)) {
      return down;
    } else {
      return up;
    }
  }
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    int times = integer(log(n) / log(3));
    return n == pow(3, times);
  }
};