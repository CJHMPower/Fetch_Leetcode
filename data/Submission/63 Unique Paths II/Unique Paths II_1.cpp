//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 63 Unique Paths II
// https://leetcode.com//problems/unique-paths-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 8.3% cpp solutions

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (obstacleGrid[0][0] != 0)
      return 0;
    else {
      dp[0][0] = 1;
    }
    int init = 1;
    for (int i = 1; i < m; i++) {
      if (obstacleGrid[i][0] != 0) {
        init = 0;
      }
      dp[i][0] = init;
    }
    init = 1;
    for (int j = 1; j < n; j++) {
      if (obstacleGrid[0][j] != 0) {
        init = 0;
      }
      dp[0][j] = init;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] != 0) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};