/*
#0001 - Easy - Two Sum
https://leetcode.com/problems/two-sum/description/
*/

#include <stdlib.h>

typedef struct {
  int value;
  int index;
} NumEntry;

static int compare(const void* a, const void* b) {
  return ((NumEntry*)a)->value - ((NumEntry*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;
  int* result = calloc(*returnSize, sizeof(int));
  if (numsSize == 2) {
    result[0] = 0;
    result[1] = 1;
  } else {
    NumEntry numarray[numsSize];
    for (int i = 0; i < numsSize; i++) {
      numarray[i].index = i;
      numarray[i].value = nums[i];
    }
    qsort(numarray, numsSize, sizeof(NumEntry), compare);
    for (int i = 0; i < numsSize; i++) {
      NumEntry search;
      search.value = target - numarray[i].value;
      NumEntry* found = (NumEntry*)bsearch(&search, numarray, numsSize,
                                           sizeof(NumEntry), compare);
      if (found != NULL) {
        result[0] = numarray[i].index;
        result[1] = found->index;
        if (result[0] == result[1]) {
          if (i < (numsSize - 1) && numarray[i + 1].value == search.value)
            result[1] = numarray[i + 1].index;
          else
            result[1] = numarray[i - 1].index;
        }
      }
    }
  }
  return result;
}
