/*
#0083 - Easy - Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head);

static struct ListNode* createListFromArray(int length, int* array) {
  struct ListNode* newlist = NULL;
  struct ListNode* last = NULL;
  for (int i = 0; i < length; i++) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = array[i];
    temp->next = NULL;
    if (newlist == NULL)
      newlist = temp;
    else
      last->next = temp;
    last = temp;
  }
  return newlist;
}

static void freeList(struct ListNode* list) {
  while (list != NULL) {
    struct ListNode* nx = list->next;
    free(list);
    list = nx;
  }
}

char* listToString(struct ListNode* list) {
  int len = 1;
  char buf[20];
  struct ListNode* p = list;
  while (p != NULL) {
    len += sprintf(buf, "%s%d", len > 1 ? " -> " : "", p->val);
    p = p->next;
  }
  char* s = (char*)malloc(len);
  s[0] = '\0';
  while (list != NULL) {
    sprintf(s + strlen(s), "%s%d", s[0] != '\0' ? " -> " : "", list->val);
    list = list->next;
  }
  return s;
}

static void do_test(int* a, int asize, char* expected) {
  struct ListNode* head = createListFromArray(asize, a);
  char* shead = listToString(head);
  struct ListNode* lresult = deleteDuplicates(head);
  char* actual = listToString(lresult);
  printf("List          : %s\n", shead);
  printf("Expected      : %s\n", expected);
  printf("Actual        : %s\n", actual);
  printf("-> %s\n\n", strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
  free(shead);
  freeList(lresult);
}

int main(void) {
  do_test((int[]){1, 1, 2}, 3, "1 -> 2");
  do_test((int[]){1, 1, 2, 3, 3}, 5, "1 -> 2 -> 3");
  do_test((int[]){1, 1}, 2, "1");
  do_test((int[]){1}, 1, "1");
  do_test((int[]){}, 0, "");
  return 0;
}
