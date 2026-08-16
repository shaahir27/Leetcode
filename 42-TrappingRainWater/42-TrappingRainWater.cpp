// Last updated: 8/16/2026, 11:46:19 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int left = 0;
5        int right = height.size() - 1;
6
7        int leftMax = 0;
8        int rightMax = 0;
9
10        int water = 0;
11
12        while (left < right) {
13            if (height[left] < height[right]) {
14                if (height[left] >= leftMax) {
15                    leftMax = height[left];
16                } 
17                else {
18                    water += leftMax - height[left];
19                }
20                left++;
21            } 
22            else {
23                if (height[right] >= rightMax) {
24                    rightMax = height[right];
25                }
26                else {
27                    water += rightMax - height[right];
28                }
29                right--;
30            }
31        }
32
33        return water;
34    }
35};