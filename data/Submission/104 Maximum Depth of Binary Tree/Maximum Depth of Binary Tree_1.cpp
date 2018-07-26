//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 104 Maximum Depth of Binary Tree
// https://leetcode.com//problems/maximum-depth-of-binary-tree/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 8 ms
// This solution defeats 1.92% cpp solutions

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
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};