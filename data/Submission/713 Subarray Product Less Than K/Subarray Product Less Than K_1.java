// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 713 Subarray Product Less Than K
// https://leetcode.com//problems/subarray-product-less-than-k/description/
// Fetched at 2018-07-24
// Submitted 1 month, 3 weeks ago
// Runtime: 29 ms
// This solution defeats 3.4% java solutions

class Solution {

  public int numSubarrayProductLessThanK(int[] nums, int k) {
    int n = nums.length, ret = 0;

    int high = 0, product = 1, last = 1;
    for (int i = 0; i < n; i++) {

      if (i > 0) {
        if (i - 1 != high) {
          product /= nums[i - 1];
        } else {
          high = i;
        }
      }

      while (high < n && product * nums[high] < k) {
        product *= nums[high];

        high++;
      }
      ret += (high - i);
    }

    return ret;
  }
}
