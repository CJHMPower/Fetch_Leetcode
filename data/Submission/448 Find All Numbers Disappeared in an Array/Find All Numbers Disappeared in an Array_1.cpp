//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 448 Find All Numbers Disappeared in an Array
// https://leetcode.com//problems/find-all-numbers-disappeared-in-an-array/description/
// Fetched at 2018-07-24
// Submitted 4 months, 1 week ago
// Runtime: 154 ms
// This solution defeats 4.17% cpp solutions

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[abs(nums[i]) - 1] > 0) {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        ret.push_back(i + 1);
      }
    }
    return ret;
  }
};