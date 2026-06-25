/*
#0011 - Medium - Container With Most Water
https://leetcode.com/problems/container-with-most-water/description/
*/

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int maxArea(int* height, int heightSize) {
  int left = 0;
  int right = heightSize - 1;
  int vol = (right - left) * MIN(height[left], height[right]);
  while (left < right) {
    if (height[left] < height[right])
      left++;
    else
      right--;
    vol = MAX(vol, (right - left) * MIN(height[left], height[right]));
  }
  return vol;
}