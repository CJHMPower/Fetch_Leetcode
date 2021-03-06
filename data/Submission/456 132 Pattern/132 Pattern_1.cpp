//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 456 132 Pattern
// https://leetcode.com//problems/132-pattern/description/
// Fetched at 2018-07-24
// Submitted 4 months, 2 weeks ago
// Runtime: 24 ms
// This solution defeats 38.93% cpp solutions

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int s3 = INT_MIN;
    stack<int> rt;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < s3) {
        return true;
      } else {
        while (!rt.empty() && rt.top() < nums[i]) {
          s3 = rt.top();
          rt.pop();
        }
      }
      rt.push(nums[i]);
    }
    return false;
  }
};