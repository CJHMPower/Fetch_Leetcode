//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 556 Next Greater Element III
// https://leetcode.com//problems/next-greater-element-iii/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 3 ms
// This solution defeats 2.22% cpp solutions

class Solution {
 public:
  int build_number(int n, int cur1, int cur2,
                   priority_queue<int, vector<int>, greater<int>>& left) {
    left.push(cur1);
    n /= 100;
    vector<int> temp;
    while (!left.empty()) {
      int top = left.top();
      left.pop();
      if (top > cur2) {
        n = 10 * n + top;
        left.push(cur2);
        break;
      } else {
        temp.push_back(top);
      }
    }
    for (auto a : temp) {
      left.push(a);
    }
    while (!left.empty()) {
      int top = left.top();
      left.pop();
      if ((INT_MAX - top) / n < 10) {
        return -1;
      }
      n = 10 * n + top;
    }
    return n;
  }

  int nextGreaterElement(int n) {
    int cur1 = -1, cur2 = 10;
    int i = 0;
    int m = n;
    priority_queue<int, vector<int>, greater<int>> left;
    while (n) {
      cur1 = n % 10;
      if (n >= 10) {
        cur2 = (n / 10) % 10;
      } else {
        return -1;
      }
      if (cur1 > cur2) {
        return build_number(n, cur1, cur2, left);
      } else {
        left.push(cur1);
      }
      n /= 10;
      i++;
    }
    return -1;
  }
};