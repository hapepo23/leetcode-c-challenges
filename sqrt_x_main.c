/*
#0069 - Easy - Sqrt(x)
https://leetcode.com/problems/sqrtx/description/
*/

#include <stdio.h>

int mySqrt(int x);

static void do_test(int x, int expected) {
  int actual = mySqrt(x);
  printf("Input: %d, expected: %d, actual: %d -> %s\n", x, expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(4, 2);
  do_test(8, 2);
  do_test(2147483647, 46340);
  return 0;
}
