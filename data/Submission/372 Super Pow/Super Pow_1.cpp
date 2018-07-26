//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 372 Super Pow
// https://leetcode.com//problems/super-pow/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 24 ms
// This solution defeats 9.71% cpp solutions

class Solution {  // a*b=(a%k)*(b%k)%k;
 public:
  const int base = 1337;
  int pow_mod(int m, int k) {
    if (k == 0) {
      return 1;
    }
    return ((m % base) * pow_mod(m, k - 1)) % base;
  }
  int superPow(int a, vector<int>& b) {
    if (b.empty()) {
      return 1;
    }
    int temp = b.back();
    b.pop_back();
    return (pow_mod(superPow(a, b), 10) * pow_mod(a, temp)) % base;
  }
};