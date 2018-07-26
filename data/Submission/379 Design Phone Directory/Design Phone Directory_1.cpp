//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 379 Design Phone Directory
// https://leetcode.com//problems/design-phone-directory/description/
// Fetched at 2018-07-24
// Submitted 2 months, 2 weeks ago
// Runtime: 60 ms
// This solution defeats 9.41% cpp solutions

class PhoneDirectory {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  PhoneDirectory(int maxNumbers) {
    used = vector<bool>(maxNumbers, false);
    next = 0;
    left = maxNumbers;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (left == 0) {
      return -1;
    }
    left--;
    int i = next;
    used[next] = true;
    if (left > 0) {
      while (used[next] == true) next = (next + 1) % used.size();
    }

    return i;
  }

  /** Check if a number is available or not. */
  bool check(int number) { return !used[number]; }

  /** Recycle or release a number. */
  void release(int number) {
    if (used[number] == true) {
      used[number] = false;
      next = number;
      left++;
    }
  }
  vector<bool> used;
  int next;
  int left;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */