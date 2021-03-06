//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 102 Binary Tree Level Order Traversal
// https://leetcode.com//problems/binary-tree-level-order-traversal/description/
// Fetched at 2018-07-24
// Submitted 4 months, 4 weeks ago
// Runtime: 6 ms
// This solution defeats 2.09% cpp solutions

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
  void levelOrder(TreeNode* root, int i, vector<vector<int>>& ret) {
    if (root == NULL) {
      return;
    }
    if (ret.size() <= i) {
      vector<int> p;
      p.push_back(root->val);
      ret.push_back(p);
    } else {
      ret[i].push_back(root->val);
    }
    levelOrder(root->left, i + 1, ret);
    levelOrder(root->right, i + 1, ret);
  }
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    levelOrder(root, 0, ret);
    return ret;
  }
};