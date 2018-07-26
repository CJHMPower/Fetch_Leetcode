//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 54 Spiral Matrix
// https://leetcode.com//problems/spiral-matrix/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) {
      return result;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int d1 = 0, d2 = n - 1, d3 = 0, d4 = m - 1;
    while (result.size() < m * n) {
      for (int i = d3; i <= d2; i++) result.push_back(matrix[d1][i]);
      d1++;
      for (int i = d1; i <= d4; i++) result.push_back(matrix[i][d2]);
      d2--;
      for (int i = d2; i >= d3; i--) result.push_back(matrix[d4][i]);
      d4--;
      for (int i = d4; i >= d1; i--) result.push_back(matrix[i][d3]);
      d3++;
    }
    if (result.size() > m * n) {
      result.erase(result.begin() + m * n, result.end());
    }
    return result;
  }
};