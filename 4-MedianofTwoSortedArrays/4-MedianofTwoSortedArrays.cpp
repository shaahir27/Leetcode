// Last updated: 9/2/2026, 11:21:23 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
5        int n1 = nums1.size();
6        int n2 = nums2.size();
7        int low = 0, high = n1;
8
9        while(low <= high) {
10            int cut1 = (low+high) >> 1;
11            int cut2 = (n1 + n2 + 1) / 2 - cut1;
12
13            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
14            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
15
16            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
17            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
18
19            if(left1 <= right2 && left2 <= right1) {
20                if( (n1 + n2) % 2 == 0 )
21                    return (max(left1, left2) + min(right1, right2)) / 2.0;
22                else
23                    return max(left1, left2);
24            }
25            else if(left1 > right2) {
26                high = cut1 - 1;
27            }
28            else {
29                low = cut1 + 1;
30            }
31        }
32        return 0.0;
33    }
34};
35