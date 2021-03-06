//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 485 Max Consecutive Ones
// https://leetcode.com//problems/max-consecutive-ones/description/
// Fetched at 2018-07-24
// Submitted 4 months, 2 weeks ago
// Runtime: 837 ms

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ret = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        count = 0;
        int j = i;
        while (j < nums.size() && nums[j] == 1) {
          count++;
          j++;
        }
      }
      ret = max(ret, count);
    }
    return ret;
  }
};