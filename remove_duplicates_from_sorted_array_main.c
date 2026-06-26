/*
#0026 - Easy - Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize);

static void print_array(int length, int* array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(int* nums, int numsSize, int* expected, int expSize) {
  int actual[numsSize];
  memcpy(actual, nums, numsSize * sizeof(int));
  int actSize = removeDuplicates(actual, numsSize);
  printf("Array   : ");
  print_array(numsSize, nums);
  printf("Expected: ");
  print_array(expSize, expected);
  printf("Actual  : ");
  print_array(actSize, actual);
  printf("-> %s\n\n", expSize == actSize && memcmp(expected, actual,
                                                   expSize * sizeof(int)) == 0
                          ? "OK"
                          : "FAIL");
}

int main(void) {
  do_test((int[]){1, 1, 2}, 3, (int[]){1, 2}, 2);
  do_test((int[]){0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 10, (int[]){0, 1, 2, 3, 4}, 5);
  return 0;
}
