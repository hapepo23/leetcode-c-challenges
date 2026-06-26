/*
#0007 - Medium - Reverse Integer
https://leetcode.com/problems/reverse-integer/description/
*/

#include <stdio.h>

int reverse(int x);

static void do_test(int x, int expected) {
  int actual = reverse(x);
  printf("Integer: %d, Expected: %d, Actual: %d -> %s\n", x, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(123, 321);
  do_test(-123, -321);
  do_test(120, 21);
  do_test(1534236469, 0);
  do_test(1563847412, 0);
  do_test(-1563847412, 0);
  return 0;
}
