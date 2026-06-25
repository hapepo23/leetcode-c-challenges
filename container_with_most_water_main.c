/*
#0011 - Medium - Container With Most Water
https://leetcode.com/problems/container-with-most-water/description/
*/

#include <stdio.h>

int maxArea(int* height, int heightSize);

static void print_array(int length, int* array) {
  printf("{");
  for (int i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}\n");
}

static void do_test(int* height, int heightSize, int expected) {
  int actual = maxArea(height, heightSize);
  printf("Heights: ");
  print_array(heightSize, height);
  printf("Expected: %d, actual: %d -> %s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test((int[]){1, 8, 6, 2, 5, 4, 8, 3, 7}, 9, 49);
  do_test((int[]){1, 1}, 2, 1);
  return 0;
}
