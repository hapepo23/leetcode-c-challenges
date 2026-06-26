/*
#0007 - Medium - Reverse Integer
https://leetcode.com/problems/reverse-integer/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void strrev(char* string) {
  for (int i = strlen(string) - 1, j = 0; i >= j; i--, j++) {
    char temp = string[j];
    string[j] = string[i];
    string[i] = temp;
  }
}

int reverse(int x) {
  char buf[12];
  sprintf(buf, "%d", x);
  strrev(*buf == '-' ? buf + 1 : buf);
  if (buf[0] == '-' && strlen(buf) == 11 && strcmp(buf, "-2147483648") > 0)
    return 0;
  else if (buf[0] != '-' && strlen(buf) == 10 && strcmp(buf, "2147483647") > 0)
    return 0;
  else
    return atoi(buf);
}
