//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 123 Best Time to Buy and Sell Stock III
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-iii/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 16 ms
// This solution defeats 8.5% cpp solutions

class Solution {
 public:
  int maxProfit_one(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    vector<int> minp(prices.size(), 0);
    vector<int> dp(prices.size(), 0);
    dp[0] = 0;
    minp[0] = prices[0];
    for (int i = 1; i < minp.size(); i++) {
      minp[i] = min(minp[i - 1], prices[i]);
    }
    for (int i = 1; i < dp.size(); i++) {
      dp[i] = max(dp[i - 1], prices[i] - minp[i]);
    }
    return dp[dp.size() - 1];
  }
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }
    vector<int> minp(prices.size(), 0);
    vector<int> dp(prices.size(), 0);
    dp[0] = 0;
    minp[0] = prices[0];
    for (int i = 1; i < minp.size(); i++) {
      minp[i] = min(minp[i - 1], prices[i]);
    }
    for (int i = 1; i < dp.size(); i++) {
      dp[i] = max(dp[i - 1], prices[i] - minp[i]);
    }
    vector<int> maxp(prices.size(), 0);
    vector<int> dr(prices.size(), 0);
    maxp[maxp.size() - 1] = prices.back();
    dr[dr.size() - 1] = 0;
    int result = dp[dp.size() - 1];
    for (int i = prices.size() - 2; i >= 0; i--) {
      maxp[i] = max(maxp[i + 1], prices[i]);
    }
    for (int i = prices.size() - 2; i >= 0; i--) {
      dr[i] = max(dr[i + 1], maxp[i] - prices[i]);
    }
    for (int k = 1; k < prices.size() - 1; k++) {
      if (dp[k] + dr[k + 1] > result) {
        result = dp[k] + dr[k + 1];
      }
    }
    return result;
  }
};