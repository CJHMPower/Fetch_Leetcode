//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 360 Sort Transformed Array
// https://leetcode.com//problems/sort-transformed-array/description/
// Fetched at 2018-07-24
// Submitted 4 months ago
// Runtime: 10 ms

class Solution {
 public:
  int f(int a, int b, int c, int x) { return a * x * x + b * x + c; }
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> result(nums.size(), 0);
    if (a == 0) {
      if (b < 0) {
        int i = nums.size() - 1;
        for (auto x : nums) {
          result[i--] = f(0, b, c, x);
        }
      } else {
        int i = 0;
        for (auto x : nums) {
          result[i++] = f(0, b, c, x);
        }
      }
      return result;
    }
    float pivolt = -float(b) / (2 * a);

    int i = nums.size() - 1;
    int low = 0, high = nums.size() - 1;
    if (a > 0) {
      while (low <= high) {
        if (fabs(pivolt - nums[low]) > fabs(nums[high] - pivolt)) {
          result[i--] = f(a, b, c, nums[low]);
          low++;
        } else {
          result[i--] = f(a, b, c, nums[high]);
          high--;
        }
      }
    } else {
      i = 0;
      while (low <= high) {
        if (fabs(pivolt - nums[low]) > fabs(nums[high] - pivolt)) {
          result[i++] = f(a, b, c, nums[low]);
          low++;
        } else {
          result[i++] = f(a, b, c, nums[high]);
          high--;
        }
      }
    }
    return result;
  }
};