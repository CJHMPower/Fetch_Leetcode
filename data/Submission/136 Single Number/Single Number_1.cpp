//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 136 Single Number
// https://leetcode.com//problems/single-number/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 20 ms
// This solution defeats 5.85% cpp solutions

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      result = result ^ nums[i];
    }
    return result;
  }
};