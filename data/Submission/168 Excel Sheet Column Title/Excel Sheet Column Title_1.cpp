//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 168 Excel Sheet Column Title
// https://leetcode.com//problems/excel-sheet-column-title/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 0 ms
// This solution defeats 100.0% cpp solutions

class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    while (n) {
      result = char((n - 1) % 26 + 'A') + result;
      n = (n - 1) / 26;
    }
    return result;
  }
};