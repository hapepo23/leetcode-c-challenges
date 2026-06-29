/*
#0020 - Easy - Valid Parentheses
https://leetcode.com/problems/valid-parentheses/description/
*/

#include <stdbool.h>

#define MAX 10000

bool isValid(char* s) {
  char stack[MAX];
  int pos = -1;
  while (*s) {
    switch (*s) {
      case '(':
        stack[++pos] = ')';
        break;
      case '[':
        stack[++pos] = ']';
        break;
      case '{':
        stack[++pos] = '}';
        break;
      case ')':
      case ']':
      case '}':
        if (pos < 0)
          return false;
        if (stack[pos--] != *s)
          return false;
        break;
    }
    s++;
    if (pos >= MAX)
      return false;
  }
  return pos == -1;
}
