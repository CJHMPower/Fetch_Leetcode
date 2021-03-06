//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 18 4Sum
// https://leetcode.com//problems/4sum/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 156 ms
// This solution defeats 8.12% cpp solutions

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums, int aim) {
    vector<vector<int>> result;
    int low, high, target;
    for (int i = 0; i < nums.size(); i++) {
      target = aim - nums[i];
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      low = i + 1;
      high = nums.size() - 1;
      while (high > low) {
        while (low > i + 1 && nums[low] == nums[low - 1]) {
          low++;
        }
        while (high < nums.size() - 1 && nums[high] == nums[high + 1]) {
          high--;
        }
        if (!(high > low)) {
          break;
        }
        if (nums[low] + nums[high] == target) {
          result.push_back({nums[i], nums[low], nums[high]});
          low++;
          high--;
        } else if (nums[low] + nums[high] < target) {
          low++;
        } else {
          high--;
        }
      }
    }
    return result;
  }
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int temp = INT_MAX;
    while (nums.size() >= 4) {
      if (temp == nums[0]) {
        nums.erase(nums.begin());
        continue;
      }
      temp = nums[0];
      nums.erase(nums.begin());
      vector<vector<int>> vtemp = threeSum(nums, target - temp);
      for (int i = 0; i < vtemp.size(); i++) {
        vtemp[i].insert(vtemp[i].begin(), temp);
        ret.push_back(vtemp[i]);
      }
    }
    return ret;
  }
};