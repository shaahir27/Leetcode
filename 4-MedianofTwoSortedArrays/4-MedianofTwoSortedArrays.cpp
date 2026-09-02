// Last updated: 9/2/2026, 11:22:51 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
5
6        int n1 = nums1.size();
7        int n2 = nums2.size();
8        
9        int low = 0;
10        int high = n1;
11
12        while(low <= high) {
13
14            int cut1 = low + (high - low)/2;
15            int cut2 = (n1 + n2 + 1) / 2 - cut1;
16
17            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
18            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
19
20            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
21            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
22
23            if(left1 <= right2 && left2 <= right1) {
24
25                if( (n1 + n2) % 2 == 0 )
26                    return (max(left1, left2) + min(right1, right2)) / 2.0;
27                else
28                    return max(left1, left2);
29  
30            }
31            else if(left1 > right2) {
32                high = cut1 - 1;
33            }
34            else {
35                low = cut1 + 1;
36            }
37        }
38        return 0.0;
39    }
40};