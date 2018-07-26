//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 416 Partition Equal Subset Sum
// https://leetcode.com//problems/partition-equal-subset-sum/description/
// Fetched at 2018-07-24
// Submitted 4 months, 1 week ago
// Runtime: 1653 ms

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.empty()) {
      return true;
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    int half = sum / 2;
    set<int> access;
    set<int> temp;
    for (int i = 0; i < nums.size(); i++) {
      temp = access;
      for (auto it = temp.begin(); it != temp.end(); it++) {
        access.insert(nums[i] + *it);
      }
      access.insert(nums[i]);
    }
    return access.find(half) != access.end();
  }
};