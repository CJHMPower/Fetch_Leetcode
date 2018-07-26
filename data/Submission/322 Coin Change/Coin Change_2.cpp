//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 322 Coin Change
// https://leetcode.com//problems/coin-change/description/
// Fetched at 2018-07-24
// Submitted 2 years, 1 month ago
// Runtime: 116 ms
// This solution defeats 9.32% cpp solutions

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
#define INF pow(10, 7)
    vector<int> dy(amount + 1, INF);
    dy[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dy[j] = dy[j] < dy[j - coins[i]] + 1 ? dy[j] : dy[j - coins[i]] + 1;
      }
    }
    if (dy[amount] == INF)
      return -1;
    else
      return dy[amount];
  }
};