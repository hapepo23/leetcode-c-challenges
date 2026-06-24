/*
#8 - Medium - String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/description/
*/

#include <stdio.h>

int myAtoi(char* s);

static void do_test(char* s, int expected) {
  int actual = myAtoi(s);
  printf("Input: \"%s\", expected: \"%d\", actual: \"%d\" -> %s\n", s, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("42", 42);
  do_test(" -042", -42);
  do_test("1337c0d3", 1337);
  do_test("0-1", 0);
  do_test("words and 987", 0);
  do_test("2147483648", 2147483647);
  do_test("-2147483649", -2147483648);
  return 0;
}
