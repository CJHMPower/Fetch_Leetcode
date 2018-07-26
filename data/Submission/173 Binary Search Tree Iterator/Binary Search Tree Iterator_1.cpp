//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 173 Binary Search Tree Iterator
// https://leetcode.com//problems/binary-search-tree-iterator/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 28 ms
// This solution defeats 1.52% cpp solutions

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    while (root) {
      paths.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !paths.empty(); }

  /** @return the next smallest number */
  int next() {
    if (!(*this).hasNext()) {
      return 0;
    }
    TreeNode* t = paths.top();
    int val = t->val;
    t = t->right;
    paths.pop();
    while (t != nullptr) {
      paths.push(t);
      t = t->left;
    }
    return val;
  }
  stack<TreeNode*> paths;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */