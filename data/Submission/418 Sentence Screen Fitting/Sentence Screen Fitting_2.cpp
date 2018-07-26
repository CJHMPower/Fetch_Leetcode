//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 418 Sentence Screen Fitting
// https://leetcode.com//problems/sentence-screen-fitting/description/
// Fetched at 2018-07-24
// Submitted 2 months ago
// Runtime: 1820 ms

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int ret = 0;
    int j = 0;
    int left = cols, row = 0;
    while (row < rows) {
      if (left >= int(sentence[j].size())) {
        left -= sentence[j].size();
        left--;
        j++;
        if (j >= sentence.size()) {
          j = 0;
          ret++;
          if (left == 0 && rows % (row + 1) == 0) {
            return ret * (rows / (row + 1));
          }
        }
      } else {
        row++;
        left = cols;
      }
    }
    return ret;
  }
};