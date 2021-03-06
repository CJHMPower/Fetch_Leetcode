//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 4 Median of Two Sorted Arrays
// https://leetcode.com//problems/median-of-two-sorted-arrays/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 49 ms
// This solution defeats 4.07% cpp solutions

class Solution {
 public:
  int searchInsert(vector<int>& nums, int low, int high, int target) {
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
  int helper(vector<int>& nums1, vector<int>& nums2, int start1, int end1,
             int start2, int end2, int seq) {
    if (end1 < start1) {
      return nums2[seq + start2 - 1];
    }
    if (end2 < start2) {
      return nums1[seq + start1 - 1];
    }
    int m = end1 - start1 + 1, n = end2 - start2 + 1;
    if (seq == 1) {
      return min(nums1[start1], nums2[start2]);
    }
    if (seq == m + n) {
      return max(nums1[end1], nums2[end2]);
    }
    int mid1 = (start1 + end1) / 2;
    if (mid1 == start1 && nums1[mid1] <= nums2[start2]) {
      if (mid1 < end1)
        mid1++;
      else {
        return nums2[start2 + seq - 2];
      }
    }
    int mid2 = searchInsert(nums2, start2, end2, nums1[mid1]);
    if (seq - 1 == mid1 - start1 + mid2 - start2) {
      if (mid2 <= end2)
        return min(nums2[mid2], nums1[mid1]);
      else {
        return nums1[mid1];
      }
    } else if (seq - 1 < mid1 - start1 + mid2 - start2) {
      return helper(nums1, nums2, start1, mid1 - 1, start2, mid2 - 1, seq);
    } else {
      return helper(nums1, nums2, mid1, end1, mid2, end2,
                    seq - (mid1 - start1 + mid2 - start2));
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int it1 = helper(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1,
                     (m + n) / 2 + 1);
    int it2 = 0;
    if ((m + n) % 2 == 1) {
      return it1;
    } else {
      it2 = helper(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1,
                   (m + n) / 2);
    }
    return (it1 + it2) / 2.0;
  }
};