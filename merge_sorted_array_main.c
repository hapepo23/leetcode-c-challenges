/*
#0088 - Easy - Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/description/
*/

#include <stdio.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

static void print_array(int length, int* array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(int* nums1,
                    int nums1Size,
                    int m,
                    int* nums2,
                    int nums2Size,
                    int n,
                    int* expected) {
  printf("Array 1 : ");
  print_array(m, nums1);
  printf("Array 2 : ");
  print_array(n, nums2);
  int nums1cpy[m + n];
  memcpy(nums1cpy, nums1, (m + n) * sizeof(int));
  merge(nums1cpy, nums1Size, m, nums2, nums2Size, n);
  printf("Expected: ");
  print_array(m + n, expected);
  printf("Actual  : ");
  print_array(m + n, nums1cpy);
  printf("-> %s\n\n", memcmp(expected, nums1cpy, (m + n) * sizeof(int)) == 0
                          ? "OK"
                          : "FAIL");
}

int main(void) {
  do_test((int[]){4, 5, 6, 0, 0, 0}, 6, 3, (int[]){1, 2, 3}, 3, 3,
          (int[]){1, 2, 3, 4, 5, 6});
  do_test((int[]){1, 2, 3, 0, 0, 0}, 6, 3, (int[]){2, 5, 6}, 3, 3,
          (int[]){1, 2, 2, 3, 5, 6});
  do_test((int[]){1}, 1, 1, (int[]){}, 0, 0, (int[]){1});
  do_test((int[]){0}, 1, 0, (int[]){1}, 1, 1, (int[]){1});
  return 0;
}
