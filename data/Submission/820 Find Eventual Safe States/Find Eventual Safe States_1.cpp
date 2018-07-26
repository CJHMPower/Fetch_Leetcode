//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 820 Find Eventual Safe States
// https://leetcode.com//problems/find-eventual-safe-states/description/
// Fetched at 2018-07-24
// Submitted 2 months, 2 weeks ago
// Runtime: 190 ms
// This solution defeats 15.32% cpp solutions

class Solution {
 public:
  vector<int> cap;
  void find_safe(vector<vector<int>>& graph, vector<vector<int>>& reverse,
                 vector<int>& ret, set<int> safe) {
    set<int> next;
    for (auto it = safe.begin(); it != safe.end(); it++) {
      for (auto a : reverse[*it]) {
        cap[a]--;
        if (cap[a] == 0) {
          next.insert(a);
          ret.push_back(a);
        }
      }
    }
    if (next.size() > 0) {
      find_safe(graph, reverse, ret, next);
    }
  }
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> reverse(n, vector<int>());

    vector<int> ret;
    set<int> safe;
    for (int i = 0; i < n; i++) {
      cap.push_back(graph[i].size());
      if (graph[i].size() == 0) {
        ret.push_back(i);
        safe.insert(i);
      }
      for (auto u : graph[i]) {
        reverse[u].push_back(i);
      }
    }
    find_safe(graph, reverse, ret, safe);
    sort(ret.begin(), ret.end());
    return ret;
  }
};