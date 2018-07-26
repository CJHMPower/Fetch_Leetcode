//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 544 Output Contest Matches
// https://leetcode.com//problems/output-contest-matches/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 10 ms
// This solution defeats 1.52% cpp solutions

class Solution {
 public:
  string recursive(vector<string> teams) {
    int n = teams.size();
    if (n < 2) {
      return teams[0];
    }
    vector<string> ret;
    for (int i = 0; i < n / 2; i++) {
      ret.push_back("(" + teams[i] + "," + teams[n - 1 - i] + ")");
    }
    return recursive(ret);
  }
  string findContestMatch(int n) {
    vector<string> teams(n, "");
    for (int i = 1; i <= n; i++) {
      teams[i - 1] = to_string(i);
    }
    return recursive(teams);
  }
};