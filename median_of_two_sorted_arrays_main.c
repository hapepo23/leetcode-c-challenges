/*
Hard
00004 Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

#include <math.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1,
                              int nums1Size,
                              int* nums2,
                              int nums2Size);

static void print_array(int length, int* array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(int* nums1,
                    int nums1Size,
                    int* nums2,
                    int nums2Size,
                    double expected) {
  double actual = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
  printf("Array 1: ");
  print_array(nums1Size, nums1);
  printf("Array 2: ");
  print_array(nums2Size, nums2);
  printf("expected: %.5g, actual: %.5g -> %s\n\n", expected, actual,
         fabs(expected - actual) < 1e-8 ? "OK" : "FAIL");
}

int main(void) {
  do_test((int[]){1, 3}, 2, (int[]){2}, 1, 2.0);
  do_test((int[]){1, 2}, 2, (int[]){3, 4}, 2, 2.5);
  do_test((int[]){5, 6}, 2, (int[]){3, 4}, 2, 4.5);
  do_test((int[]){}, 0, (int[]){3, 4}, 2, 3.5);
  do_test((int[]){1, 2}, 2, (int[]){}, 0, 1.5);
  return 0;
}
