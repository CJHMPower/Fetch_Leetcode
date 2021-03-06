//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 417 Pacific Atlantic Water Flow
// https://leetcode.com//problems/pacific-atlantic-water-flow/description/
// Fetched at 2018-07-24
// Submitted 5 months ago
// Runtime: 96 ms
// This solution defeats 14.55% cpp solutions

class Solution {
 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> ret;
    if (matrix.empty()) {
      return ret;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<pair<bool, bool>>> reach(
        m, vector<pair<bool, bool>>(n, make_pair(false, false)));
    for (int i = 0; i < n; i++) {
      reach[0][i].first = true;
      reach[m - 1][i].second = true;
    }
    for (int i = 0; i < m; i++) {
      reach[i][0].first = true;
      reach[i][n - 1].second = true;
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (reach[i][j].first && reach[i][j].second == true) {
          ret.push_back(make_pair(i, j));
          continue;
        }
        if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i - 1][j].first;
          reach[i][j].second |= reach[i - 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j - 1].first;
          reach[i][j].second |= reach[i][j - 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (i + 1 < m && matrix[i + 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i + 1][j].first;
          reach[i][j].second |= reach[i + 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j + 1 < n && matrix[i][j + 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j + 1].first;
          reach[i][j].second |= reach[i][j + 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (reach[i][j].first && reach[i][j].second == true) {
          continue;
        }
        if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i - 1][j].first;
          reach[i][j].second |= reach[i - 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j - 1].first;
          reach[i][j].second |= reach[i][j - 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (i + 1 < m && matrix[i + 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i + 1][j].first;
          reach[i][j].second |= reach[i + 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j + 1 < n && matrix[i][j + 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j + 1].first;
          reach[i][j].second |= reach[i][j + 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (reach[i][j].first && reach[i][j].second == true) {
          continue;
        }
        if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i - 1][j].first;
          reach[i][j].second |= reach[i - 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j - 1].first;
          reach[i][j].second |= reach[i][j - 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (i + 1 < m && matrix[i + 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i + 1][j].first;
          reach[i][j].second |= reach[i + 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j + 1 < n && matrix[i][j + 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j + 1].first;
          reach[i][j].second |= reach[i][j + 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (reach[i][j].first && reach[i][j].second == true) {
          continue;
        }
        if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i - 1][j].first;
          reach[i][j].second |= reach[i - 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j - 1].first;
          reach[i][j].second |= reach[i][j - 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (i + 1 < m && matrix[i + 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i + 1][j].first;
          reach[i][j].second |= reach[i + 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j + 1 < n && matrix[i][j + 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j + 1].first;
          reach[i][j].second |= reach[i][j + 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (reach[i][j].first && reach[i][j].second == true) {
          continue;
        }
        if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i - 1][j].first;
          reach[i][j].second |= reach[i - 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j - 1].first;
          reach[i][j].second |= reach[i][j - 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (i + 1 < m && matrix[i + 1][j] <= matrix[i][j]) {
          reach[i][j].first |= reach[i + 1][j].first;
          reach[i][j].second |= reach[i + 1][j].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
        if (j + 1 < n && matrix[i][j + 1] <= matrix[i][j]) {
          reach[i][j].first |= reach[i][j + 1].first;
          reach[i][j].second |= reach[i][j + 1].second;
          if (reach[i][j].first && reach[i][j].second == true) {
            ret.push_back(make_pair(i, j));
            continue;
          }
        }
      }
    }
    return ret;
  }
};