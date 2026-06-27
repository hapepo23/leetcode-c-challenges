/*
#0148 - Medium - Sort List
https://leetcode.com/problems/sort-list/description/
*/

#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

static int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head) {
  int node_count = 0;
  struct ListNode* p = head;
  while (p != NULL) {
    node_count++;
    p = p->next;
  }
  if (node_count > 1) {
    int vector[node_count];
    int i = 0;
    p = head;
    while (p != NULL) {
      vector[i++] = p->val;
      struct ListNode* nx = p->next;
      free(p);
      p = nx;
    }
    qsort(vector, node_count, sizeof(int), compare);
    struct ListNode* newlist = NULL;
    struct ListNode* last = NULL;
    for (int i = 0; i < node_count; i++) {
      struct ListNode* temp = malloc(sizeof(struct ListNode));
      temp->val = vector[i];
      temp->next = NULL;
      if (newlist == NULL)
        newlist = temp;
      else
        last->next = temp;
      last = temp;
    }
    head = newlist;
  }
  return head;
}