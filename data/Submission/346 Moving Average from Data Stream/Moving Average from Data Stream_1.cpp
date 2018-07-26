//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 346 Moving Average from Data Stream
// https://leetcode.com//problems/moving-average-from-data-stream/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 38 ms
// This solution defeats 3.42% cpp solutions

class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) { len = size; }

  double next(int val) {
    if (q.size() < len) {
      q.push(val);
      sum += val;
      return double(sum) / q.size();
    } else {
      sum -= q.front();
      q.pop();
      q.push(val);
      sum += val;
      return double(sum) / q.size();
    }
  }
  queue<int> q;
  int len;
  int sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */