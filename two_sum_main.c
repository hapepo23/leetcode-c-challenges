/*
#0001 - Easy - Two Sum
https://leetcode.com/problems/two-sum/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

static void print_array(int length, int* array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(int* nums, int numsSize, int target, int* expected) {
  int returnSize = 0;
  int* actual = twoSum(nums, numsSize, target, &returnSize);
  printf("Array: ");
  print_array(numsSize, nums);
  printf("Target: %d\n", target);
  printf("Expected: ");
  print_array(2, expected);
  printf("Actual: ");
  print_array(returnSize, actual);
  printf("-> %s\n\n",
         (returnSize == 2) &&
                 ((actual[0] == expected[0] && actual[1] == expected[1]) ||
                  (actual[1] == expected[0] && actual[0] == expected[1]))
             ? "OK"
             : "FAIL");
  free(actual);
}

int main(void) {
  do_test((int[]){2, 7, 11, 15}, 4, 9, (int[]){0, 1});
  do_test((int[]){3, 2, 4}, 3, 6, (int[]){1, 2});
  do_test((int[]){3, 3}, 2, 6, (int[]){0, 1});
  do_test((int[]){2, 5, 5, 11}, 4, 10, (int[]){1, 2});
  do_test((int[]){50000000, 3, 2, 4, 50000000}, 5, 100000000, (int[]){0, 4});
  return 0;
}
