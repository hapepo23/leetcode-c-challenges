/*
#0021 - Easy - Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

#include <stddef.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  struct ListNode* newlist = NULL;
  struct ListNode* last;
  struct ListNode* node;
  while (list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      node = list1;
      list1 = list1->next;
    } else {
      node = list2;
      list2 = list2->next;
    }
    if (newlist == NULL)
      newlist = node;
    else
      last->next = node;
    last = node;
  }
  node = list1 != NULL ? list1 : list2;
  if (newlist == NULL)
    newlist = node;
  else
    last->next = node;
  return newlist;
}