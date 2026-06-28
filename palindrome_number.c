/*
#0009 - Easy - Palindrome Number
https://leetcode.com/problems/palindrome-number/description/
*/

#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
  if (x < 0)
    return false;
  if (x < 10)
    return true;
  char s[11];
  int l = sprintf(s, "%d", x);
  int left = 0;
  int right = l - 1;
  while (left < right && s[left] == s[right]) {
    left++;
    right--;
  }
  return left == ((l % 2 ? 0 : 1) + right);
}