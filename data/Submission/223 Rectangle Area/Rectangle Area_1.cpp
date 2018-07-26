//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 223 Rectangle Area
// https://leetcode.com//problems/rectangle-area/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 42 ms
// This solution defeats 2.41% cpp solutions

class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int width = min(min(C - E, G - A), min(G - E, C - A));
    int height = min(min(D - B, H - F), min(D - F, H - B));
    if (width <= 0 || height <= 0) {
      return (C - A) * (D - B) + (H - F) * (G - E);
    }
    return (C - A) * (D - B) + (H - F) * (G - E) - width * height;
  }
};