//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 582 Kill Process
// https://leetcode.com//problems/kill-process/description/
// Fetched at 2018-07-24
// Submitted 2 months, 1 week ago
// Runtime: 234 ms
// This solution defeats 1.22% cpp solutions

class Solution {
 public:
  void kill_recur(map<int, vector<int>>& tree, vector<int>& ret, int kill) {
    ret.push_back(kill);
    for (auto a : tree[kill]) {
      kill_recur(tree, ret, a);
    }
  }
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    map<int, vector<int>> tree;
    for (int i = 0; i < pid.size(); i++) {
      if (tree.find(ppid[i]) == tree.end()) tree[ppid[i]] = vector<int>();
      tree[ppid[i]].push_back(pid[i]);
    }
    vector<int> ret;
    kill_recur(tree, ret, kill);
    return ret;
  }
};
