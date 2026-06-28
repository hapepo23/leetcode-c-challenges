/*
#0009 - Easy - Palindrome Number
https://leetcode.com/problems/palindrome-number/description/
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x);

static void do_test(int x, bool expected) {
  bool actual = isPalindrome(x);
  printf("Number: %d, expected: \"%s\", actual: \"%s\" -> %s\n", x,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(121, true);
  do_test(123321, true);
  do_test(122, false);
  do_test(123421, false);
  do_test(-121, false);
  do_test(10, false);
  return 0;
}
