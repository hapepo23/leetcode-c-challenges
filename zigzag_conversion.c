/*
#0006 - Medium - Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/description/
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
  int l = strlen(s);
  char* result = calloc(l + 1, sizeof(char));
  if (numRows <= 1 || numRows >= l)
    strcpy(result, s);
  else {
    int rownums[l];
    bool up = true;
    int row = 0;
    for (int i = 0; i < l; i++) {
      rownums[i] = row;
      if (up)
        up = ++row != (numRows - 1);
      else
        up = --row == 0;
    }
    int pos = 0;
    for (int i = 0; i < numRows; i++)
      for (int j = 0; j < l; j++)
        if (rownums[j] == i)
          result[pos++] = s[j];
  }
  return result;
}