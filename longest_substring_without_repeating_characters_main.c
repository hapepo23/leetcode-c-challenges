/*
#0003 - Medium - Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

#include <stdio.h>

int lengthOfLongestSubstring(char* s);

static void do_test(char* s, int expected) {
  int actual = lengthOfLongestSubstring(s);
  printf("String = \"%s\", expected = %d, actual = %d -> %s\n", s, expected,
         actual, actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("abcabcbb", 3);
  do_test("bbbbb", 1);
  do_test("pwwkew", 3);
  do_test("", 0);
  do_test(" ", 1);
  do_test("dvdf", 3);
  do_test("ckilbkd", 5);
  do_test("tmmzuxt", 5);
  do_test("au", 2);
  do_test("aabaab!bb", 3);
  return 0;
}
