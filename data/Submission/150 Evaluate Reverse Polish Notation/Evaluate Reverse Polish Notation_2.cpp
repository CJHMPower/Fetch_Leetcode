//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 150 Evaluate Reverse Polish Notation
// https://leetcode.com//problems/evaluate-reverse-polish-notation/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 16 ms
// This solution defeats 5.89% cpp solutions

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    if (tokens.empty()) {
      return 0;
    }
    stack<int> operand;
    operand.push(stoi(tokens[0]));
    int i = 1;
    while (i < tokens.size()) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
          tokens[i] == "/") {
        int op1 = operand.top();
        operand.pop();
        int op2 = operand.top();
        operand.pop();
        if (tokens[i] == "+") {
          operand.push(op1 + op2);
        } else if (tokens[i] == "-") {
          operand.push(op2 - op1);
        } else if (tokens[i] == "*") {
          operand.push(op1 * op2);
        } else if (tokens[i] == "/") {
          operand.push(op2 / op1);
        }
      } else {
        operand.push(stoi(tokens[i]));
      }
      i++;
    }
    return operand.top();
  }
};