//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 9 Palindrome Number
// https://leetcode.com//problems/palindrome-number/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 88 ms
// This solution defeats 94.76% cpp solutions

class Solution {
 public:
  int reverse(int x) {
    long long int t = x;
    if (t >= INT_MAX || t <= INT_MIN) {
      return 0;
    }
    long long int result = 0;
    int digit;
    int minus = 1;
    if (x < 0) {
      minus = -1;
    }
    x = abs(x);
    while (x) {
      digit = x % 10;
      x /= 10;
      result = 10 * result + minus * digit;
      if ((minus == 1 && result > INT_MAX) ||
          (minus == -1 && result < (signed int)0x80000000)) {
        return 0;
      }
    }
    return (int)result;
  }
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    return reverse(x) == x;
  }
};