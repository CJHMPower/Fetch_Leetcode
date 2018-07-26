//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 475 Heaters
// https://leetcode.com//problems/heaters/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 90 ms
// This solution defeats 6.62% cpp solutions

class Solution {
 public:
  int binary_search(vector<int>& heaters, int target) {
    int low = 0, high = heaters.size() - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (heaters[mid] == target) {
        return 0;
      } else if (heaters[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    int ret = INT_MAX;
    if (low < heaters.size()) {
      ret = min(ret, abs(heaters[low] - target));
    }
    if (high >= 0) {
      ret = min(ret, abs(heaters[high] - target));
    }
    return ret;
  }
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ret = 0;
    int dist = 0;
    for (int i = 0; i < houses.size(); i++) {
      dist = binary_search(heaters, houses[i]);
      ret = max(ret, dist);
    }
    return ret;
  }
};