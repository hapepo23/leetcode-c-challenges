/*
#0002 - Medium - Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

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
  char* s = malloc(100);
  s[0] = '\0';
  while (list != NULL) {
    if (s[0] != '\0')
      s = strcat(s, " -> ");
    sprintf(s + strlen(s), "%d", list->val);
    list = list->next;
  }
  return s;
}

static void do_test(int* a1, int a1size, int* a2, int a2size, char* expected) {
  struct ListNode* l1 = createListFromArray(a1size, a1);
  struct ListNode* l2 = createListFromArray(a2size, a2);
  struct ListNode* l3 = addTwoNumbers(l1, l2);
  char* actual = listToString(l3);
  char* sl1 = listToString(l1);
  char* sl2 = listToString(l2);
  printf("List1   : %s\n", sl1);
  printf("List2   : %s\n", sl2);
  printf("Expected: %s\n", expected);
  printf("Actual  : %s\n", actual);
  printf("-> %s\n\n", strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
  free(sl1);
  free(sl2);
  freeList(l1);
  freeList(l2);
  freeList(l3);
}

int main(void) {
  do_test((int[]){2, 4, 3}, 3, (int[]){5, 6, 4}, 3, "7 -> 0 -> 8");
  do_test((int[]){0}, 1, (int[]){0}, 1, "0");
  do_test((int[]){9, 9, 9, 9, 9, 9, 9}, 7, (int[]){9, 9, 9, 9}, 4,
          "8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1");
  return 0;
}
