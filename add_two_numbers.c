/*
#0002 - Medium - Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/
*/

#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int d1, d2, sum, carryover;
  struct ListNode* newlist = NULL;
  struct ListNode* last = NULL;
  carryover = 0;
  while (l1 != NULL || l2 != NULL || carryover > 0) {
    if (l1 != NULL) {
      d1 = l1->val;
      l1 = l1->next;
    } else
      d1 = 0;
    if (l2 != NULL) {
      d2 = l2->val;
      l2 = l2->next;
    } else
      d2 = 0;
    sum = d1 + d2 + carryover;
    carryover = sum / 10;
    sum = sum % 10;
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = sum;
    temp->next = NULL;
    if (newlist == NULL)
      newlist = temp;
    else
      last->next = temp;
    last = temp;
  }
  return newlist;
}
