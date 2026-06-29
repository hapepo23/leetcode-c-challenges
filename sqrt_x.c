/*
#0069 - Easy - Sqrt(x)
https://leetcode.com/problems/sqrtx/description/
*/

// Algorithm:
// https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_binary_search

typedef long long LONG;

int mySqrt(int x) {
  LONG l = 0;
  LONG r = (LONG)x + 1;
  while (l != r - 1) {
    LONG m = (l + r) / 2;
    if (m * m <= (LONG)x)
      l = m;
    else
      r = m;
  }
  return (int)l;
}
