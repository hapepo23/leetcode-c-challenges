/*
#0020 - Easy - Valid Parentheses
https://leetcode.com/problems/valid-parentheses/description/
*/

#include <stdbool.h>
#include <stdio.h>

bool isValid(char* s);

static void do_test(char* s, bool expected) {
  bool actual = isValid(s);
  printf("Input: \"%s\", expected: %s, actual: %s -> %s\n", s,
         expected ? "true" : "false", actual ? "true" : "false",
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("()", true);
  do_test("()[]{}", true);
  do_test("(]", false);
  do_test("([])", true);
  do_test("([)]", false);
  do_test("]]]]", false);
  do_test("[[[[", false);
  return 0;
}
