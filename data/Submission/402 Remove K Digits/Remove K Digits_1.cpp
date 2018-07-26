//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 402 Remove K Digits
// https://leetcode.com//problems/remove-k-digits/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 23 ms
// This solution defeats 3.87% cpp solutions

class Solution {
 public:
  pair<int, char> find_min(string& num, int start, int end) {
    pair<int, char> result = {0, '9'};
    for (int i = start; i <= end; i++) {
      if (num[i] < result.second) {
        result = {i, num[i]};
      }
    }
    return result;
  }
  string removeKdigits(string num, int k) {
    int n = num.size();
    stack<int> stk;
    int i = 0;
    while (i < n) {
      int tmp = num[i] - '0';
      if (stk.empty() || k <= 0) {
        stk.push(tmp);
      } else {
        while (!stk.empty() && stk.top() > tmp && k > 0) {
          stk.pop();
          k--;
        }
        stk.push(tmp);
      }
      i++;
    }

    while (k > 0) {
      stk.pop();
      k--;
    }

    string res = "";
    while (!stk.empty()) {
      res = to_string(stk.top()) + res;
      stk.pop();
    }
    i = 0;
    while (res[i] == '0') {
      i++;
    }
    res = res.substr(i);
    return res == "" ? "0" : res;
  }
};