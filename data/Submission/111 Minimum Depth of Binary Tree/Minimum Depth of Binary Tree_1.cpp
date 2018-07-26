//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 111 Minimum Depth of Binary Tree
// https://leetcode.com//problems/minimum-depth-of-binary-tree/description/
// Fetched at 2018-07-24
// Submitted 2 years, 2 months ago
// Runtime: 16 ms

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    int depth1 = minDepth(root->left);
    int depth2 = minDepth(root->right);
    if (depth1 == 0) return depth2 + 1;
    if (depth2 == 0)
      return depth1 + 1;
    else
      return depth1 < depth2 ? depth1 + 1 : depth2 + 1;
  }
};