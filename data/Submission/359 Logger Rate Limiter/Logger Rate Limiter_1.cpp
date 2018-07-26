//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 359 Logger Rate Limiter
// https://leetcode.com//problems/logger-rate-limiter/description/
// Fetched at 2018-07-24
// Submitted 2 months, 2 weeks ago
// Runtime: 73 ms
// This solution defeats 3.67% cpp solutions

class Logger {
 public:
  /** Initialize your data structure here. */
  Logger() {}

  /** Returns true if the message should be printed in the given timestamp,
     otherwise returns false. If this method returns false, the message will not
     be printed. The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (printed.find(message) == printed.end() ||
        timestamp - printed[message] >= 10) {
      printed[message] = timestamp;
      return true;
    }

    return false;
  }
  map<string, int> printed;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */