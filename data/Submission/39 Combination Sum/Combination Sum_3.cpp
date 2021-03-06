//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 39 Combination Sum
// https://leetcode.com//problems/combination-sum/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 259 ms

class Solution {
 public:
  vector<vector<int>> helper(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.empty()) {
      return result;
    }
    if (target == 0) {
      result.push_back(vector<int>());
      return result;
    }
    if (target < candidates[0]) {
      return result;
    }
    for (auto v : candidates) {
      vector<vector<int>> temp = helper(candidates, target - v);
      for (int i = 0; i < temp.size(); i++) {
        temp[i].push_back(v);
        sort(temp[i].begin(), temp[i].end());
        if (find(result.begin(), result.end(), temp[i]) == result.end())
          result.push_back(temp[i]);
      }
    }
    return result;
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return helper(candidates, target);
  }
};