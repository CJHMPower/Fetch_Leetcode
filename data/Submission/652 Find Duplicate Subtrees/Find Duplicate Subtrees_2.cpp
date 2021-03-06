//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 652 Find Duplicate Subtrees
// https://leetcode.com//problems/find-duplicate-subtrees/description/
// Fetched at 2018-07-24
// Submitted 1 month ago
// Runtime: 432 ms
// This solution defeats 1.41% cpp solutions

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
  string HashCode(TreeNode* root) {
    if (root == NULL) return "";
    return to_string(root->val) + "l" + HashCode(root->left) + "r" +
           HashCode(root->right);
  }

  void traverseSubtree(TreeNode* root, set<string>& hash, set<string>& pushed,
                       vector<TreeNode*>& ret) {
    if (root == NULL) return;
    string hashCode = HashCode(root);
    if (hash.find(hashCode) != hash.end() &&
        pushed.find(hashCode) == pushed.end()) {
      ret.push_back(root);
      pushed.insert(hashCode);
    } else
      hash.insert(hashCode);
    traverseSubtree(root->left, hash, pushed, ret);
    traverseSubtree(root->right, hash, pushed, ret);
  }
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ret;
    set<string> hash;
    set<string> pushed;
    traverseSubtree(root, hash, pushed, ret);
    return ret;
  }
};