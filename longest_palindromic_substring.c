/*
#0005 - Medium - Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/
*/

#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
  int n = strlen(s);
  if (n == 0) {
    char* res = (char*)malloc(1);
    res[0] = '\0';
    return res;
  }
  int start = 0;
  int maxLen = 1;
  for (int i = 0; i < n; i++) {
    int left = i;
    int right = i;
    while (left >= 0 && right < n && s[left] == s[right]) {
      if (right - left + 1 > maxLen) {
        maxLen = right - left + 1;
        start = left;
      }
      left--;
      right++;
    }
    left = i;
    right = i + 1;
    while (left >= 0 && right < n && s[left] == s[right]) {
      if (right - left + 1 > maxLen) {
        maxLen = right - left + 1;
        start = left;
      }
      left--;
      right++;
    }
  }
  char* result = (char*)malloc(maxLen + 1);
  strncpy(result, s + start, maxLen);
  result[maxLen] = '\0';
  return result;
}