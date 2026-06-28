/*
#0088 - Easy - Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/description/
*/

#include <string.h>

#define UNUSED(x) (void)(x)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  UNUSED(nums1Size);
  UNUSED(nums2Size);
  if (n == 0)
    return;
  if (m == 0)
    memcpy(nums1, nums2, n * sizeof(int));
  else {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
}