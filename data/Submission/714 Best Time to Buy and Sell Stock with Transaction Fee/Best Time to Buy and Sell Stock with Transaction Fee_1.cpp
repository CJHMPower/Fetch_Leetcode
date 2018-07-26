//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 714 Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// Fetched at 2018-07-24
// Submitted 1 month, 1 week ago
// Runtime: 92 ms
// This solution defeats 75.28% cpp solutions

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      cash = max(cash, hold + prices[i] - fee);
      hold = max(hold, cash - prices[i]);
    }
    return cash;
  }
};