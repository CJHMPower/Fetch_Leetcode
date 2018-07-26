//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 551 Student Attendance Record I
// https://leetcode.com//problems/student-attendance-record-i/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 6 ms
// This solution defeats 1.21% cpp solutions

class Solution {
 public:
  bool checkRecord(string s) {
    int count_A = 0;
    int count_L = 0;
    for (auto c : s) {
      if (c == 'A') {
        count_L = 0;
        count_A++;
        if (count_A > 1) {
          return false;
        }
      } else if (c == 'L') {
        count_L++;
        if (count_L > 2) {
          return false;
        }
      } else {
        count_L = 0;
      }
    }
    return true;
  }
};