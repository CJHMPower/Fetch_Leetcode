//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 507 Perfect Number
// https://leetcode.com//problems/perfect-number/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 6 ms
// This solution defeats 14.4% cpp solutions

class Solution {
 public:
  set<int> divisors(int num) {
    int ceil = int(sqrt(num));
    set<int> ret = {1};
    for (int i = 2; i <= ceil; i++) {
      if (num % i == 0) {
        ret.insert(i);
        ret.insert(num / i);
      }
    }
    return ret;
  }
  bool checkPerfectNumber(int num) {
    if (num < 2) {
      return false;
    }
    set<int> ret = divisors(num);
    int sum = 0;
    for (auto it = ret.begin(); it != ret.end(); it++) {
      sum += *it;
    }
    return sum == num;
  }
};