//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 636 Exclusive Time of Functions
// https://leetcode.com//problems/exclusive-time-of-functions/description/
// Fetched at 2018-07-24
// Submitted 2 months, 1 week ago
// Runtime: 32 ms
// This solution defeats 10.92% cpp solutions

class Solution {
 public:
  vector<int> split(string s) {
    vector<int> ret;
    int i = 0;
    while (s[i] != ':') i++;
    ret.push_back(stoi(s.substr(0, i)));
    i++;
    if (s[i] == 's') {
      ret.push_back(0);
    } else {
      ret.push_back(1);
    }

    while (s[i] != ':') i++;

    ret.push_back(stoi(s.substr(i + 1, s.size() - i - 1)));
    return ret;
  }
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<int, int>> s;
    vector<int> ret(n, 0);
    vector<int> log = split(logs[0]);
    s.push(make_pair(log[0], log[2]));
    pair<int, int> top;
    for (int i = 1; i < logs.size(); i++) {
      vector<int> log = split(logs[i]);
      if (s.empty()) {
        s.push(make_pair(log[0], log[2]));
        continue;
      }
      top = s.top();

      if (log[1] == 0) {
        ret[top.first] += (log[2] - top.second);
        s.push(make_pair(log[0], log[2]));

      } else {
        ret[top.first] += (log[2] - top.second + 1);
        s.pop();

        if (s.size() > 0) {
          int t = s.top().first;
          s.pop();
          s.push(make_pair(t, log[2] + 1));
        }
      }
    }
    return ret;
  }
};