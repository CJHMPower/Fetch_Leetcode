//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 314 Binary Tree Vertical Order Traversal
// https://leetcode.com//problems/binary-tree-vertical-order-traversal/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 4 ms
// This solution defeats 23.91% cpp solutions

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
  void traverse(TreeNode *root, map<int, vector<pair<int, int>>> &ret,
                int height, int pos, int &min_val, int &max_val) {
    if (root == NULL) {
      return;
    }

    min_val = min(pos, min_val);
    max_val = max(pos, max_val);
    if (ret.find(pos) != ret.end()) {
      ret[pos].push_back(make_pair(height, root->val));
    } else {
      ret[pos] = vector<pair<int, int>>{make_pair(height, root->val)};
    }
    traverse(root->left, ret, height + 1, pos - 1, min_val, max_val);
    traverse(root->right, ret, height + 1, pos + 1, min_val, max_val);
  }

  vector<vector<int>> verticalOrder(TreeNode *root) {
    if (!root) {
      return vector<vector<int>>();
    }
    map<int, vector<pair<int, int>>> hash;
    int min_val = INT_MAX, max_val = 0;
    traverse(root, hash, 0, 0, min_val, max_val);
    vector<vector<int>> ret(abs(min_val) + max_val + 1, vector<int>{});
    for (auto it = hash.begin(); it != hash.end(); it++) {
      sort(it->second.begin(), it->second.end(),
           [](pair<int, int> &a, pair<int, int> &b) {
             return a.first < b.first;
           });
      for (auto a : it->second) {
        ret[it->first + abs(min_val)].push_back(a.second);
      }
    }
    return ret;
  }
};