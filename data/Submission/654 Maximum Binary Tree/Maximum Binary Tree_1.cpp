//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 654 Maximum Binary Tree
// https://leetcode.com//problems/maximum-binary-tree/description/
// Fetched at 2018-07-24
// Submitted 5 months, 1 week ago
// Runtime: 73 ms
// This solution defeats 4.12% cpp solutions

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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
      return NULL;
    }
    int value = nums[0];
    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > value) {
        value = nums[i];
        index = i;
      }
    }
    vector<int> left;
    left.assign(nums.begin(), nums.begin() + index);
    vector<int> right;
    right.assign(nums.begin() + index + 1, nums.end());
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = value;
    TreeNode* left_child = constructMaximumBinaryTree(left);
    TreeNode* right_child = constructMaximumBinaryTree(right);
    root->left = left_child;
    root->right = right_child;
    return root;
  }
};