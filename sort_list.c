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
  int x = *(int*)a;
  int y = *(int*)b;
  return (x > y) - (x < y);
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
      p = p->next;
    }
    qsort(vector, node_count, sizeof(int), compare);
    p = head;
    for (int i = 0; i < node_count; i++) {
      p->val = vector[i];
      p = p->next;
    }
  }
  return head;
}