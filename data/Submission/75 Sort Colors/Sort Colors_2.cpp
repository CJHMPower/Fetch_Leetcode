//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 75 Sort Colors
// https://leetcode.com//problems/sort-colors/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 4.71% cpp solutions

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (auto v : nums) {
      switch (v) {
        case 0:
          count0++;
          break;
        case 1:
          count1++;
          break;
        case 2:
          count2++;
          break;
      }
    }
    int i = 0;
    while (i < count0) {
      nums[i] = 0;
      i++;
    }
    int j = 0;
    while (j + count0 < nums.size() && j < count1) {
      nums[j + count0] = 1;
      j++;
    }
    j = 0;
    while (j < count2 && j + count0 + count1 < nums.size()) {
      nums[count0 + count1 + j] = 2;
      j++;
    }
  }
};