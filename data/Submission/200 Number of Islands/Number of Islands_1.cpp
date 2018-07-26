//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 200 Number of Islands
// https://leetcode.com//problems/number-of-islands/description/
// Fetched at 2018-07-24
// Submitted 2 months, 4 weeks ago
// Runtime: 15 ms
// This solution defeats 7.75% cpp solutions

class Solution {
 public:
  void DFS(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] != '1') {
      return;
    }
    grid[i][j] = '0';
    DFS(grid, i - 1, j);
    DFS(grid, i + 1, j);
    DFS(grid, i, j - 1);
    DFS(grid, i, j + 1);
  }
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int ret = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          DFS(grid, i, j);
          ret++;
        }
      }
    }
    return ret;
  }
};