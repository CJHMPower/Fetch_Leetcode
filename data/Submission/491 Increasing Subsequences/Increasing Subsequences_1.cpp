//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 491 Increasing Subsequences
// https://leetcode.com//problems/increasing-subsequences/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 262 ms
// This solution defeats 7.65% cpp solutions

class Solution {
 public:
  void DFS(int index, vector<int>& nums, vector<vector<int>>& ret) {
    if (index < 0) {
      return;
    }

    DFS(index - 1, nums, ret);

    int n = ret.size();
    for (int i = 0; i < n; i++) {
      vector<int> temp = ret[i];
      if (nums[index] >= temp.back()) {
        temp.push_back(nums[index]);
        ret.push_back(temp);
      }
    }

    for (int i = index - 1; i >= 0; i--) {
      if (nums[index] >= nums[i]) {
        ret.push_back(vector<int>{nums[i], nums[index]});
      }
    }
  }
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() < 2) {
      return ret;
    }
    DFS(nums.size() - 1, nums, ret);
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
  }
};