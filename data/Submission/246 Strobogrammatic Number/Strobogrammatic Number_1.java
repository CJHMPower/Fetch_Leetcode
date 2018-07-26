// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 246 Strobogrammatic Number
// https://leetcode.com//problems/strobogrammatic-number/description/
// Fetched at 2018-07-24
// Submitted 1 month, 4 weeks ago
// Runtime: 2 ms
// This solution defeats 0.61% java solutions

class Solution {
  public boolean isStrobogrammatic(String num) {
    HashMap<Character, Character> map = new HashMap<Character, Character>();
    map.put('6', '9');
    map.put('9', '6');
    map.put('8', '8');
    map.put('1', '1');
    map.put('0', '0');
    for (int i = 0; i <= num.length() / 2; i++) {
      if (!map.containsKey(num.charAt(i))
          || map.get(num.charAt(i)) != num.charAt(num.length() - 1 - i)) {
        return false;
      }
    }
    return true;
  }
}
