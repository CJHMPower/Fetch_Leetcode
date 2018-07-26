//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 216 Combination Sum III
// https://leetcode.com//problems/combination-sum-iii/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 3 ms
// This solution defeats 2.49% cpp solutions

class Solution {
 public:
  long long int fact(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  }
  void next(vector<int>& nums) {
    if (nums.back() != 9) {
      nums[nums.size() - 1]++;
      return;
    }
    int i = nums.size() - 1;
    while (i >= 0 && nums[i] == 9 - (nums.size() - 1 - i)) {
      i--;
    }
    if (i < 0) {
      return;
    } else {
      nums[i]++;
      for (int j = i + 1; j < nums.size(); j++) {
        nums[j] = nums[j - 1] + 1;
      }
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums;
    vector<vector<int>> result;
    if (n < 0 || k < 1) {
      return result;
    }
    for (int i = 1; i <= k; i++) {
      nums.push_back(i);
    }
    int times = fact(9) / (fact(k) * fact(9 - k));
    for (int i = 0; i < times; i++) {
      if (accumulate(nums.begin(), nums.end(), 0) == n) {
        result.push_back(nums);
      }
      next(nums);
    }
    return result;
  }
};