// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 625 Minimum Factorization
// https://leetcode.com//problems/minimum-factorization/description/
// Fetched at 2018-07-24
// Submitted 3 weeks, 3 days ago
// Runtime: 18 ms
// This solution defeats 6.87% java solutions

class Solution {
  public String smallestFactorString(int a) {
    if (a < 10) return a + "";
    String minDigit = new String();
    for (int i = 9; i >= 2; i--) {
      if ((a % 9 == 0 && i == 3)
          || (a % 8 == 0 && (i == 2 || i == 4))
          || (a % 6 == 0 && (i == 2 || i == 3))
          || (a % 4 == 0 && i == 2)) {
        continue;
      }
      if (a % i == 0) {
        String recur = smallestFactorString(a / i);
        if (recur.length() == 0) continue;
        int j = 0;
        while (j < recur.length() && recur.charAt(j) < (char) (i + '0')) j++;
        String result = recur.substring(0, j) + i;
        if (j < recur.length()) result = result + recur.substring(j);
        if (minDigit.length() == 0
            || result.length() < minDigit.length()
            || (result.length() == minDigit.length() && result.compareTo(minDigit) < 0)) {
          minDigit = result;
        }
      }
    }
    return minDigit;
  }

  public int smallestFactorization(int a) {
    if (a < 10) return a;
    String minDigit = smallestFactorString(a);
    String maxInt = new String(Integer.MAX_VALUE + "");
    if (minDigit.length() == 0
        || minDigit.length() > maxInt.length()
        || (minDigit.length() == maxInt.length() && minDigit.compareTo(maxInt) > 0)) {
      return 0;
    }
    return Integer.parseInt(minDigit);
  }
}
