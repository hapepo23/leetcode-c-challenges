/*
#4 - Hard - Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

/* --- Solution 1, with temp. array ---

double findMedianSortedArrays(int* nums1,
                              int nums1Size,
                              int* nums2,
                              int nums2Size) {
  int numsSize = nums1Size + nums2Size;
  int nums[numsSize], j = 0, k = 0;
  for (int i = 0; i < nums1Size; i++) {
    while (j < nums2Size && nums2[j] <= nums1[i])
      nums[k++] = nums2[j++];
    nums[k++] = nums1[i];
  }
  while (j < nums2Size)
    nums[k++] = nums2[j++];
  return 0.5 * (nums[numsSize / 2] + nums[(numsSize - 1) / 2]);
}

*/

/* --- Solution 2, without temp. array --- */

#define CHECK_SET_MEDIAN_VALUES(val, inc) \
  {                                       \
    if (k == medpos1)                     \
      medval1 = val;                      \
    if (k == medpos2)                     \
      medval2 = val;                      \
    k++;                                  \
    inc;                                  \
  }

double findMedianSortedArrays(int* nums1,
                              int nums1Size,
                              int* nums2,
                              int nums2Size) {
  int numsSize = nums1Size + nums2Size;
  int j = 0, k = 0;
  int medpos1 = (numsSize - 1) / 2, medpos2 = numsSize / 2;
  int medval1 = 0, medval2 = 0;
  for (int i = 0; i < nums1Size && k <= medpos2; i++) {
    while (j < nums2Size && nums2[j] <= nums1[i] && k <= medpos2)
      CHECK_SET_MEDIAN_VALUES(nums2[j], j++)
    if (k <= medpos2)
      CHECK_SET_MEDIAN_VALUES(nums1[i], ;)
  }
  while (j < nums2Size && k <= medpos2)
    CHECK_SET_MEDIAN_VALUES(nums2[j], j++)
  return 0.5 * (medval1 + medval2);
}
