//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 474 Ones and Zeroes
// https://leetcode.com//problems/ones-and-zeroes/description/
// Fetched at 2018-07-24
// Submitted 3 months, 3 weeks ago
// Runtime: 103 ms
// This solution defeats 11.61% cpp solutions

class Solution {
 public:
  pair<int, int> counts(string s) {
    int ret1 = 0, ret2 = 0;
    for (auto c : s) {
      if (c == '0') {
        ret1++;
      } else if (c == '1') {
        ret2++;
      }
    }
    return make_pair(ret1, ret2);
  }
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(strs.size() + 1, vector<int>((m + 1) * (n + 1), 0));

    for (int k = 1; k <= strs.size(); k++) {
      pair<int, int> count = counts(strs[k - 1]);
      for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
          if (i < count.first || j < count.second) {
            dp[k][i * (n + 1) + j] = dp[k - 1][i * (n + 1) + j];
          } else {
            int ridx = i - count.first;
            int cidx = j - count.second;
            dp[k][i * (n + 1) + j] = max(dp[k - 1][ridx * (n + 1) + cidx] + 1,
                                         dp[k - 1][i * (1 + n) + j]);
          }
        }
      }
    }
    return dp[strs.size()].back();
  }
};