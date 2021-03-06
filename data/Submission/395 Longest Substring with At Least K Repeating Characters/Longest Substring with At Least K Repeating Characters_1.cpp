//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 395 Longest Substring with At Least K Repeating Characters
// https://leetcode.com//problems/longest-substring-with-at-least-k-repeating-characters/description/
// Fetched at 2018-07-24
// Submitted 4 months ago
// Runtime: 126 ms
// This solution defeats 13.9% cpp solutions

class Solution {
 public:
  int longestSubstring(string &s, int low, int high, int k) {
    if (high - low < k) {
      return 0;
    }
    vector<int> hash(26, 0);
    bool flag = false;
    for (int i = low; i < high; i++) {
      hash[s[i] - 'a']++;
      if (hash[s[i] - 'a'] >= k) {
        flag = true;
      }
    }
    if (flag == false) {
      return 0;
    }
    int ret = 0;
    flag = false;
    for (int i = low; i < high; i++) {
      if (hash[s[i] - 'a'] < k) {
        int longest1 = longestSubstring(s, low, i, k);
        int longest2 = longestSubstring(s, i + 1, high, k);
        ret = max(ret, max(longest1, longest2));
        flag = true;
        break;
      }
    }
    if (flag == false) {
      return high - low;
    }

    return ret;
  }
  int longestSubstring(string s, int k) {
    return longestSubstring(s, 0, s.size(), k);
  }
};