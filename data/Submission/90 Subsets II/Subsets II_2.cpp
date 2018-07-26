//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 90 Subsets II
// https://leetcode.com//problems/subsets-ii/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 26 ms

class Solution {
 public:
  void backtrace(vector<int>& nums, int index, vector<vector<int>>& ret) {
    if (index >= nums.size()) {
      return;
    }
    int n = ret.size();
    for (int i = 0; i < n; i++) {
      auto ele = ret[i];
      ele.push_back(nums[index]);
      ret.push_back(ele);
    }
    backtrace(nums, index + 1, ret);
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    result.push_back(vector<int>());
    backtrace(nums, 0, result);
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
    result.erase(it, result.end());
    return result;
  }
};