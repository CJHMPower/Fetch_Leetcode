//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 92 Reverse Linked List II
// https://leetcode.com//problems/reverse-linked-list-ii/description/
// Fetched at 2018-07-24
// Submitted 2 years ago
// Runtime: 4 ms
// This solution defeats 4.23% cpp solutions

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr || head->next == nullptr || m >= n) {
      return head;
    }
    int i = 0;
    ListNode* start = head;
    ListNode* end = head;
    while (i < m - 2) {
      start = start->next;
      i++;
    }
    ListNode* tails = start;
    if (m > 1) {
      start = start->next;
    }
    end = start;
    i = m - 1;
    while (i < n - 1) {
      end = end->next;
      i++;
    }
    ListNode* back = end->next;
    ListNode* p1 = start;
    ListNode* p2 = start->next;
    ListNode* p3 = p2->next;
    while (p1 != end) {
      p2->next = p1;
      p1 = p2;
      p2 = p3;
      if (p3 != nullptr) p3 = p3->next;
    }
    start->next = back;
    if (m > 1) {
      tails->next = end;
    }
    if (head == start) {
      head = end;
    }
    return head;
  }
};