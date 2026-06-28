/*
#0006 - Medium - Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows);

static void do_test(char* s, int numRows, char* expected) {
  char* actual = convert(s, numRows);
  printf("Input: \"%s\", rows: %d, expected: \"%s\", actual: \"%s\" -> %s\n", s,
         numRows, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test("PAYPALISHIRING", 1, "PAYPALISHIRING");
  do_test("PAYPALISHIRING", 2, "PYAIHRNAPLSIIG");
  do_test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
  do_test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
  do_test("PAYPALISHIRING", 14, "PAYPALISHIRING");
  do_test("PAYPALISHIRING", 15, "PAYPALISHIRING");
  return 0;
}
