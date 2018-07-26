//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 477 Total Hamming Distance
// https://leetcode.com//problems/total-hamming-distance/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 64 ms
// This solution defeats 5.41% cpp solutions

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int ret = 0;
    int m = 0;
    bool flag = false;
    while (flag == false) {
      m = 0;
      flag = true;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
          m++;
        }
        nums[i] = nums[i] >> 1;
        if (nums[i] != 0) {
          flag = false;
        }
      }
      ret += m * (nums.size() - m);
    }
    return ret;
  }
};