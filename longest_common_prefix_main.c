/*
#0014 - Easy - Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

static void print_string_array(int length, char** array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("\"%s\"%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(char** strs, int strsSize, char* expected) {
  char* actual = longestCommonPrefix(strs, strsSize);
  printf("Strings: ");
  print_string_array(strsSize, strs);
  printf("Expected: \"%s\", actual: \"%s\" -> %s\n\n", expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test((char*[]){"flower", "flow", "flight"}, 3, "fl");
  do_test((char*[]){"dog", "racecar", "car"}, 3, "");
  do_test((char*[]){"hi", "hi", "hi"}, 3, "hi");
  do_test((char*[]){""}, 1, "");
  return 0;
}
