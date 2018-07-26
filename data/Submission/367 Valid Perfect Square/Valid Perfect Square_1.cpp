//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 367 Valid Perfect Square
// https://leetcode.com//problems/valid-perfect-square/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  bool isPerfectSquare(int num) {
    long long int low = 0, high = num;
    long long int mid;
    while (high >= low) {
      mid = (low + high) / 2;
      if (mid * mid == num) {
        return true;
      } else if (mid * mid > num) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return false;
  }
};