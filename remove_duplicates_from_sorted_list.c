/*
#0083 - Easy - Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
*/

#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
  if (head == NULL)
    return head;
  struct ListNode* p = head;
  struct ListNode* last = p;
  p = p->next;
  while (p != NULL) {
    if (p->val == last->val) {  // delete
      struct ListNode* nx = p->next;
      free(p);
      p = nx;
    } else {  // keep
      last->next = p;
      last = p;
      p = p->next;
    }
  }
  last->next = NULL;
  return head;
}