//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 164 Maximum Gap
// https://leetcode.com//problems/maximum-gap/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 13 ms
// This solution defeats 2.77% cpp solutions

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int max = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (abs(nums[i] - nums[i + 1]) > max) {
        max = abs(nums[i] - nums[i + 1]);
      }
    }
    return max;
  }
};