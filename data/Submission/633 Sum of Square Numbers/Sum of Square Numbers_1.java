// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 633 Sum of Square Numbers
// https://leetcode.com//problems/sum-of-square-numbers/description/
// Fetched at 2018-07-24
// Submitted 3 weeks, 2 days ago
// Runtime: 40 ms
// This solution defeats 25.98% java solutions

class Solution {
  long square(int c) {
    long low = 0, high = c, mid, pow;
    while (low <= high) {
      mid = (low + high) / 2;
      pow = mid * mid;
      if (pow == c) return mid;
      else if (pow < c) low = mid + 1;
      else high = mid - 1;
    }
    return -1;
  }

  public boolean judgeSquareSum(int c) {
    int mid = (int) Math.sqrt(c / 2);
    for (int i = 0; i <= mid; i++) {
      if (square(c - i * i) >= 0) return true;
    }
    return false;
  }
}