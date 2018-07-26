// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 739 Daily Temperatures
// https://leetcode.com//problems/daily-temperatures/description/
// Fetched at 2018-07-24
// Submitted 1 month, 4 weeks ago
// Runtime: 66 ms
// This solution defeats 47.23% java solutions

class Solution {
  class Pair {
    int first;
    int second;

    Pair(int a, int b) {
      first = a;
      second = b;
    }
  }

  public int[] dailyTemperatures(int[] temperatures) {
    int n = temperatures.length;
    int ret[] = new int[n];
    Stack<Pair> st = new Stack<Pair>();
    ret[n - 1] = 0;
    st.push(new Pair(n - 1, temperatures[n - 1]));
    for (int i = n - 2; i >= 0; i--) {
      while (!st.isEmpty() && st.peek().second <= temperatures[i]) {
        st.pop();
      }
      if (st.isEmpty()) {
        ret[i] = 0;
      } else {
        ret[i] = st.peek().first - i;
      }
      st.push(new Pair(i, temperatures[i]));
    }
    return ret;
  }
}