//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 694 Number of Distinct Islands
// https://leetcode.com//problems/number-of-distinct-islands/description/
// Fetched at 2018-07-24
// Submitted 2 months, 4 weeks ago
// Runtime: 40 ms
// This solution defeats 10.75% cpp solutions

class Solution {
 public:
  void DFS(vector<vector<int>>& grid, int i, int j,
           vector<pair<int, int>>& island) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] != 1) {
      return;
    }
    grid[i][j] = 0;
    island.push_back(make_pair(i, j));
    DFS(grid, i - 1, j, island);
    DFS(grid, i + 1, j, island);
    DFS(grid, i, j - 1, island);
    DFS(grid, i, j + 1, island);
  }
  bool cmp(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
    if (a.size() != b.size()) {
      return false;
    }
    int f = a[0].first - b[0].first;
    int s = a[0].second - b[0].second;
    for (int i = 1; i < a.size(); i++) {
      if (a[i].first - b[i].first != f || a[i].second - b[i].second != s) {
        return false;
      }
    }
    return true;
  }
  int numDistinctIslands(vector<vector<int>>& grid) {
    vector<vector<pair<int, int>>> islands;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> island;
          DFS(grid, i, j, island);
          int k = 0;
          for (; k < islands.size(); k++) {
            if (cmp(islands[k], island) == true) {
              break;
            }
          }
          if (k >= islands.size()) {
            islands.push_back(island);
          }
        }
      }
    }
    return islands.size();
  }
};