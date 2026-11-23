// Last updated: 11/23/2026, 10:50:52 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        int left = 0;
5        int right = x;
6
7        while(left<=right){
8            int mid = left + (right - left)/2;
9
10            if((long long)mid*mid <= x){
11                left = mid + 1;
12            }
13            else{
14                right = mid - 1;
15            }
16        }
17
18        return right;
19    }
20};