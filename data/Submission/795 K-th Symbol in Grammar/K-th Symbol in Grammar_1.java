// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 795 K-th Symbol in Grammar
// https://leetcode.com//problems/k-th-symbol-in-grammar/description/
// Fetched at 2018-07-24
// Submitted 3 weeks, 3 days ago
// Runtime: 4 ms
// This solution defeats 7.49% java solutions

class Solution {
  public int pow2(int n) {
    int ret = 1;
    if (n == 0) return ret;
    return ret << n;
  }

  public int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    int pow = pow2(N - 2);
    if (K <= pow) return kthGrammar(N - 1, K);
    else {
      return kthGrammar(N - 1, K - pow) ^ 1;
    }
  }
}
