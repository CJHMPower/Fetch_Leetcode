//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 545 Boundary of Binary Tree
// https://leetcode.com//problems/boundary-of-binary-tree/description/
// Fetched at 2018-07-24
// Submitted 2 months, 1 week ago
// Runtime: 12 ms
// This solution defeats 3.91% cpp solutions

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
  void left_traverse(TreeNode* root, vector<int>& ret, bool& protect) {
    if (root == NULL) {
      return;
    }
    if (root->left == NULL && root->right == NULL) {
      if (protect == true) {
        protect = false;
      } else {
        ret.push_back(root->val);
      }
    }

    left_traverse(root->left, ret, protect);
    left_traverse(root->right, ret, protect);
  }
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> ret;
    if (root == NULL) {
      return ret;
    }
    TreeNode* p = root;
    if (root->left != NULL) {
      while (true) {
        ret.push_back(p->val);

        if (p->left != NULL) {
          p = p->left;
        } else if (p->right != NULL) {
          p = p->right;
        } else {
          break;
        }
      }
    } else {
      ret.push_back(root->val);
    }
    bool protect = true;
    if (root->left == NULL && root->right != NULL) {
      protect = false;
    }
    left_traverse(root, ret, protect);
    vector<int> right;
    p = root->right;
    while (p) {
      if (p->right != NULL) {
        right.push_back(p->val);
        p = p->right;
      } else if (p->left != NULL) {
        right.push_back(p->val);
        p = p->left;
      } else {
        break;
      }
    }
    for (int i = 0; i < right.size(); i++) {
      ret.push_back(right[right.size() - 1 - i]);
    }
    return ret;
  }
};