/*
#0003 - Medium - Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
  bool clist[256] = {false};
  int c = 0;
  int l = strlen(s);
  if (l == 0)
    return 0;
  int left = 0;
  int right = 1;
  clist[(int)s[0]] = true;
  c++;
  int longest = 1;
  while (right < l) {
    if (clist[(int)s[right]]) {
      for (int i = left; i < right; i++)
        if (s[i] != s[right]) {
          clist[(int)s[i]] = false;
          c--;
        }
      left = right;
      while (s[left - 1] != s[right]) {
        left--;
        clist[(int)s[left]] = true;
        c++;
      }
    } else {
      clist[(int)s[right]] = true;
      c++;
      if (c > longest)
        longest = c;
    }
    right++;
  }
  return longest;
}
