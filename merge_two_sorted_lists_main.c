/*
#0021 - Easy - Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

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

static void do_test(int* a1, int a1size, int* a2, int a2size, char* expected) {
  struct ListNode* l1 = createListFromArray(a1size, a1);
  struct ListNode* l2 = createListFromArray(a2size, a2);
  char* sl1 = listToString(l1);
  char* sl2 = listToString(l2);
  struct ListNode* l3 = mergeTwoLists(l1, l2);
  char* actual = listToString(l3);
  printf("List1   : %s\n", sl1);
  printf("List2   : %s\n", sl2);
  printf("Expected: %s\n", expected);
  printf("Actual  : %s\n", actual);
  printf("-> %s\n\n", strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
  free(sl1);
  free(sl2);
  freeList(l3);
}

int main(void) {
  do_test((int[]){1, 2, 4}, 3, (int[]){1, 3, 4}, 3,
          "1 -> 1 -> 2 -> 3 -> 4 -> 4");
  do_test((int[]){1, 2}, 2, (int[]){3, 4}, 2, "1 -> 2 -> 3 -> 4");
  do_test((int[]){3, 4}, 2, (int[]){1, 2}, 2, "1 -> 2 -> 3 -> 4");
  do_test((int[]){}, 0, (int[]){}, 0, "");
  do_test((int[]){}, 0, (int[]){0}, 1, "0");
  do_test((int[]){0}, 1, (int[]){}, 0, "0");
  return 0;
}
