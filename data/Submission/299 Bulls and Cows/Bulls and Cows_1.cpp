//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 299 Bulls and Cows
// https://leetcode.com//problems/bulls-and-cows/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 6 ms
// This solution defeats 9.21% cpp solutions

class Solution {
 public:
  string getHint(string secret, string guess) {
    vector<int> hash1(10, 0);
    vector<int> hash2(10, 0);
    int bull = 0, cow = 0;
    for (int i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) {
        bull++;
      } else {
        hash1[secret[i] - '0']++;
        hash2[guess[i] - '0']++;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (hash1[i] > 0 && hash2[i] > 0) {
        cow += min(hash1[i], hash2[i]);
      }
    }
    string result;
    result = to_string(bull) + "A" + to_string(cow) + "B";
    return result;
  }
};