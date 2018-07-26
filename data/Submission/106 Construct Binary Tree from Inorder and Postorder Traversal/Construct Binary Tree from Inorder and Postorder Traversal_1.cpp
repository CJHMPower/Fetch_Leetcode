//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 106 Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com//problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 24 ms
// This solution defeats 16.55% cpp solutions

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
  void rebuild(int* postorder, int* inorder, int len, TreeNode** root) {
    if (postorder == nullptr || inorder == nullptr) return;
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = *(postorder + len - 1);
    temp->left = nullptr;
    temp->right = nullptr;
    if (*root == nullptr) *root = temp;
    if (len == 1) return;
    int* p = inorder;
    while (*p != *(postorder + len - 1)) {
      p++;
    }
    int left_len = int(p - inorder);
    int right_len = len - left_len - 1;
    if (left_len > 0) {
      rebuild(postorder, inorder, left_len, &((*root)->left));
    }
    if (right_len > 0) {
      rebuild(postorder + left_len, inorder + left_len + 1, right_len,
              &((*root)->right));
    }
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
      return nullptr;
    }
    int* inord = new int[inorder.size()];
    int* post = new int[inorder.size()];
    for (int i = 0; i < inorder.size(); i++) {
      inord[i] = inorder[i];
      post[i] = postorder[i];
    }
    TreeNode* root = nullptr;
    rebuild(post, inord, inorder.size(), &root);
    return root;
  }
};