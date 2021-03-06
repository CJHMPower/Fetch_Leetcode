//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 117 Populating Next Right Pointers in Each Node II
// https://leetcode.com//problems/populating-next-right-pointers-in-each-node-ii/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 42 ms
// This solution defeats 3.0% cpp solutions

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<TreeLinkNode*>> level;
  void levelorder(TreeLinkNode* root, int depth) {
    if (root == NULL) {
      return;
    }
    if (level.size() == depth) {
      level.push_back(vector<TreeLinkNode*>());
    }
    level[depth].push_back(root);
    levelorder(root->left, depth + 1);
    levelorder(root->right, depth + 1);
  }
  void connect(TreeLinkNode* root) {
    if (root == nullptr) {
      return;
    }
    levelorder(root, 0);
    queue<TreeLinkNode*> start;
    for (int i = 0; i < level.size(); i++) {
      start.push(level[i][0]);
    }
    deque<TreeLinkNode*> layer;
    layer.push_back(root);
    while (!layer.empty()) {
      if (layer.front() == start.front()) {
        start.pop();
        for (int i = 0; i < layer.size() - 1; i++) {
          layer[i]->next = layer[i + 1];
        }
        layer.back()->next = nullptr;
      }
      if (layer.front()->left != nullptr) {
        layer.push_back(layer.front()->left);
      }
      if (layer.front()->right != nullptr) {
        layer.push_back(layer.front()->right);
      }
      layer.pop_front();
    }
  }
};