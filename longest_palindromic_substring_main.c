/*
#0005 - Medium - Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s);

static void do_test(char* s, char* expected) {
  char* actual = longestPalindrome(s);
  printf("String = \"%s\", expected = \"%s\", actual = \"%s\" -> %s\n", s,
         expected, actual, strcmp(actual, expected) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("babad", "bab");
  do_test("cbbd", "bb");
  return 0;
}
