//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 267 Palindrome Permutation II
// https://leetcode.com//problems/palindrome-permutation-ii/description/
// Fetched at 2018-07-24
// Submitted 3 months ago
// Runtime: 3 ms
// This solution defeats 5.73% cpp solutions

class Solution {
 public:
  void backtrace(string& s, int start, int n, vector<string>& ret,
                 map<char, int>& hash) {
    if (start >= n) {
      ret.push_back(s);
      return;
    }

    for (auto it = hash.begin(); it != hash.end(); it++) {
      if (it->second > 0) {
        hash[it->first]--;
        s.push_back(it->first);
        backtrace(s, start + 1, n, ret, hash);
        s.pop_back();
        hash[it->first]++;
      }
    }
  }
  vector<string> permute(string& s) {
    vector<string> ret;
    string start = "";
    map<char, int> hash;
    for (auto c : s) {
      if (hash.find(c) != hash.end()) {
        hash[c]++;
      } else {
        hash[c] = 1;
      }
    }
    backtrace(start, 0, s.size(), ret, hash);
    return ret;
  }
  vector<string> generatePalindromes(string s) {
    vector<string> ret;
    map<char, int> hash;
    for (auto c : s) {
      if (hash.find(c) != hash.end()) {
        hash[c]++;
      } else {
        hash[c] = 1;
      }
    }
    string temp;
    bool flag = true;
    string odd = "";
    for (auto it = hash.begin(); it != hash.end(); it++) {
      if (it->second % 2 == 0) {
        temp = temp + string(it->second / 2, it->first);
      } else {
        if (flag == true) {
          flag = false;
          odd = string(1, it->first);
          temp = temp + string(it->second / 2, it->first);
        } else {
          return ret;
        }
      }
    }
    vector<string> collect = permute(temp);
    for (auto r : collect) {
      string temp = r;
      r = r + odd;
      reverse(temp.begin(), temp.end());
      r = r + temp;
      ret.push_back(r);
    }
    return ret;
  }
};