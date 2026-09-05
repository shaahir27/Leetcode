// Last updated: 9/5/2026, 11:45:22 PM
1class Solution {
2private:
3    int findPeak(vector<vector<int>>& mat, int col) {
4        int n = mat.size();
5
6        int maxRow = 0;
7
8        for(int i = 1; i < n; i++) {
9            if(mat[i][col] > mat[maxRow][col]) {
10                maxRow = i;
11            }
12        }
13
14        return maxRow;
15    }
16
17public:
18    vector<int> findPeakGrid(vector<vector<int>>& mat) {
19        int n = mat.size();
20        int m = mat[0].size();
21
22        int low = 0;
23        int high = m - 1;
24
25        while(low <= high) {
26
27            int mid = low + (high - low) / 2;
28
29            // Call helper function inside while loop
30            int row = findPeak(mat, mid);
31
32            int left = (mid > 0) ? mat[row][mid - 1] : -1;
33            int right = (mid < m - 1) ? mat[row][mid + 1] : -1;
34
35            // Peak found
36            if(mat[row][mid] > left && mat[row][mid] > right) {
37                return {row, mid};
38            }
39
40            // Move left
41            else if(left > mat[row][mid]) {
42                high = mid - 1;
43            }
44
45            // Move right
46            else {
47                low = mid + 1;
48            }
49        }
50
51        return {-1, -1};
52    }
53};
54
55
56/*
57
58class Solution {
59private:
60    int findPeak(vector<int> nums){
61        int n = nums.size();
62
63        if(n == 1) return 0;
64
65        int low = 1;
66        int high = n-1;
67
68        while(low<=high){
69            int mid = low + (high - low)/2;
70
71            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
72                return mid;
73            }
74            // increasing slope
75            else if(nums[mid-1]<nums[mid]){
76                low = mid+1;
77            }
78            //decreasing slope
79            else{
80                high = mid-1;
81            }
82        }
83
84        return -1;
85    }
86
87public:
88    vector<int> findPeakGrid(vector<vector<int>>& mat) {
89        int n = mat.size();
90        vector<int> result;
91
92        for(int i=0; i<n; i++){
93            int peak = findPeak(mat[i]);
94            if(peak == -1){
95                continue;
96            }
97            else{
98                result.push_back(peak);
99            }
100        }
101
102        return result;        
103    }
104};
105
106*/