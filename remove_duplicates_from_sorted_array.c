/*
#0026 - Easy - Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 1)
    return numsSize;
  int lastidx = 0;
  int result = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[lastidx]) {
      nums[result++] = nums[i];
      lastidx = i;
    }
  }
  return result;
}