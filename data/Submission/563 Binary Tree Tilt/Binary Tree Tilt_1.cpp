//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 563 Binary Tree Tilt
// https://leetcode.com//problems/binary-tree-tilt/description/
// Fetched at 2018-07-24
// Submitted 2 months, 1 week ago
// Runtime: 16 ms
// This solution defeats 20.4% cpp solutions

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int TreeSum(TreeNode *root, int &ret) {
    if (root == NULL) {
      return 0;
    }
    int left = TreeSum(root->left, ret);
    int right = TreeSum(root->right, ret);
    ret += abs(left - right);
    return left + right + root->val;
  }
  int findTilt(TreeNode *root) {
    int ret = 0;
    TreeSum(root, ret);
    return ret;
  }
};