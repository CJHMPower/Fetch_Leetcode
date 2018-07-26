//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 565 Array Nesting
// https://leetcode.com//problems/array-nesting/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 42 ms
// This solution defeats 12.46% cpp solutions

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ret = 0;
    int k = 0;
    int temp;
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      k = 0;
      i = j;
      while (nums[i] != -1) {
        temp = nums[i];
        nums[i] = -1;
        i = temp;
        k++;
      }
      if (k > 0) ret = max(ret, k);
    }
    return ret;
  }
};