//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 338 Counting Bits
// https://leetcode.com//problems/counting-bits/description/
// Fetched at 2018-07-24
// Submitted 2 years, 2 months ago
// Runtime: 140 ms
// This solution defeats 1.41% cpp solutions

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> result;
    result.push_back(0);
    if (num == 0) return result;
    result.resize(num + 1);
    for (int i = 1; i <= num; i++) {
      result[i] = result[i - 1] + 2 - log2(((i - 1) ^ i) + 1);
    }
    return result;
  }
};