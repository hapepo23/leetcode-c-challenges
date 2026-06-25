/*
#0014 - Easy - Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/description/
*/

#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

char* longestCommonPrefix(char** strs, int strsSize) {
  int l = (int)strlen(strs[0]);
  for (int i = 1; i < strsSize; i++)
    l = MIN((int)strlen(strs[i]), l);
  char* result = calloc(l + 1, sizeof(char));
  strncpy(result, strs[0], l);
  for (int j = 0; j < l; j++)
    for (int i = 1; i < strsSize; i++)
      if (result[j] != strs[i][j]) {
        result[j] = '\0';
        return result;
      }
  return result;
}
