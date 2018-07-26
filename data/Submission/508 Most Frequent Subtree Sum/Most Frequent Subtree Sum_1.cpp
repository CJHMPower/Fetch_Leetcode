//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 508 Most Frequent Subtree Sum
// https://leetcode.com//problems/most-frequent-subtree-sum/description/
// Fetched at 2018-07-24
// Submitted 3 months, 2 weeks ago
// Runtime: 19 ms
// This solution defeats 3.7% cpp solutions

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
  int TreeSum(TreeNode* root, map<int, int>& hash) {
    if (root == NULL) {
      return 0;
    }
    if (root->left == NULL && root->right == NULL) {
      if (hash.find(root->val) == hash.end()) {
        hash[root->val] = 1;
      } else {
        hash[root->val] += 1;
      }
      return root->val;
    }
    int sum1 = TreeSum(root->left, hash);
    int sum2 = TreeSum(root->right, hash);
    int val = sum1 + sum2 + root->val;
    if (hash.find(val) == hash.end()) {
      hash[val] = 1;
    } else {
      hash[val] += 1;
    }
    return sum1 + sum2 + root->val;
  }
  vector<int> findFrequentTreeSum(TreeNode* root) {
    map<int, int> hash;
    TreeSum(root, hash);
    vector<int> result;
    int max_val = 0;
    for (auto it = hash.begin(); it != hash.end(); it++) {
      max_val = max(max_val, it->second);
    }
    for (auto it = hash.begin(); it != hash.end(); it++) {
      if (it->second == max_val) {
        result.push_back(it->first);
      }
    }
    return result;
  }
};