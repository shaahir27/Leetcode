// Last updated: 9/4/2026, 10:37:57 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6
7        int row = 0;
8        int col = m-1;
9
10        while(row < n && col >= 0){
11            if(matrix[row][col] == target) return true;
12
13            if(matrix[row][col] > target){
14                col--;
15            }
16            else{
17                row++;
18            }
19        }
20
21        return false;
22    }
23};
24
25
26/*
27
28MY APPROACH
29
30class Solution {
31public:
32    bool searchMatrix(vector<vector<int>>& matrix, int target) {
33        int n = matrix.size();
34        int m = matrix[0].size();
35
36        for(int i=0; i<n; i++){
37            int low = 0;
38            int high = m-1;
39
40            while(low <= high){
41                int mid = low + (high - low)/2;
42
43                if(matrix[i][mid] == target) return true;
44
45                if(matrix[i][mid] > target){
46                    high = mid - 1;
47                }
48                else{
49                    low = mid + 1;
50                }
51            }
52        }
53
54        return false;
55    }
56};
57
58*/