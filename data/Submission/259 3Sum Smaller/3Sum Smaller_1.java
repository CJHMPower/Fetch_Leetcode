// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 259 3Sum Smaller
// https://leetcode.com//problems/3sum-smaller/description/
// Fetched at 2018-07-24
// Submitted 1 month, 3 weeks ago
// Runtime: 13 ms
// This solution defeats 6.01% java solutions

class Solution {
  public int threeSumSmaller(int[] nums, int target) {
    Arrays.sort(nums);
    int ret = 0, i = 0, j = 1, k = nums.length - 1;
    while (i < nums.length - 2) {
      j = i + 1;
      k = nums.length - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] < target) {
          ret += (k - j);
          j++;
        } else {
          k--;
        }
      }
      i++;
    }
    return ret;
  }
}