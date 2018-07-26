//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 565 Array Nesting
// https://leetcode.com//problems/array-nesting/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 63 ms
// This solution defeats 7.51% cpp solutions

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ret = 0;
    int k = 0;
    int temp;
    for (int j = 0; j < nums.size(); j++) {
      k = 0;
      int i = j;
      while (nums[i] != -1) {
        temp = nums[i];
        nums[i] = -1;
        i = temp;
        k++;
      }
      ret = max(ret, k);
    }
    return ret;
  }
};