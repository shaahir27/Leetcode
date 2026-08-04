// Last updated: 8/4/2026, 10:42:14 PM
1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n =  nums.size();
5
6        if(n == 1) return 0;
7        if(nums[0] > nums[1]) return 0;
8        else if(nums[n-1] > nums[n-2]) return n-1;
9
10        int low = 1;
11        int high = n-1;
12
13        while(low<=high){
14            int mid = low + (high - low)/2;
15
16            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
17                return mid;
18            }
19            // increasing slope
20            else if(nums[mid-1]<nums[mid]){
21                low = mid+1;
22            }
23            //decreasing slope
24            else{
25                high = mid-1;
26            }
27        }
28
29        return -1;
30    }
31};