//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 461 Hamming Distance
// https://leetcode.com//problems/hamming-distance/description/
// Fetched at 2018-07-24
// Submitted 5 months ago
// Runtime: 6 ms

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int ret = 0;
    while (z) {
      ret += z % 2;
      z = z >> 1;
    }
    return ret;
  }
};