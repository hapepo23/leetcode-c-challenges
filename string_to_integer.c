/*
Medium
00008 String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/description/
*/

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

int myAtoi(char* s) {
  long long result = 0;
  int sign = 1;
  bool signread = false;
  bool innumber = false;
  while (*s) {
    if (!innumber && isspace(*s))
      s++;
    else if (!signread && (*s == '+' || *s == '-')) {
      sign = (*s == '-') ? -1 : 1;
      signread = true;
      innumber = true;
      s++;
    } else if (isdigit(*s)) {
      signread = true;
      innumber = true;
      result = result * 10 + (*s - '0');
      if (result * sign > INT_MAX) {
        result = INT_MAX;
        break;
      } else if (result * sign < INT_MIN) {
        result = INT_MIN;
        break;
      }
      s++;
    } else
      break;
  }
  return (int)(result * sign);
}
