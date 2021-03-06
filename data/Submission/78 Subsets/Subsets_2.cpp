//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 78 Subsets
// https://leetcode.com//problems/subsets/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 6 ms
// This solution defeats 2.15% cpp solutions

class Solution {
 public:
  void backtrace(int nums, vector<vector<int>>& result) {
    int n = result.size();
    for (int i = 0; i < n; i++) {
      vector<int> temp = result[i];
      temp.push_back(nums);
      result.push_back(temp);
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back(vector<int>());
    for (auto u : nums) {
      backtrace(u, result);
    }
    return result;
  }
};