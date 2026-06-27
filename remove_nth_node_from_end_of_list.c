/*
#0019 - Medium - Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/

#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  int node_count = 0;
  struct ListNode* p = head;
  while (p != NULL) {
    node_count++;
    p = p->next;
  }
  int delete_node_no = node_count + 1 - n;
  if (delete_node_no >= 1) {
    struct ListNode* delete_prev_node = NULL;
    struct ListNode* delete_node = head;
    int count = 1;
    while (count < delete_node_no) {
      count++;
      delete_prev_node = delete_node;
      delete_node = delete_node->next;
    }
    if (delete_prev_node == NULL)
      head = delete_node->next;
    else
      delete_prev_node->next = delete_node->next;
    free(delete_node);
  }
  return head;
}