// Last updated: 9/3/2026, 11:21:58 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6
7        int low = 0;
8        int high = (n * m) - 1;
9
10        while(low <= high){
11            int mid = low + (high - low)/2;
12
13            int i = mid/m;
14            int j = mid%m;
15
16            if(matrix[i][j] == target) return true;
17
18            if(matrix[i][j] < target){
19                low = mid + 1;
20            }
21            else{
22                high = mid - 1;
23            }
24        }
25
26        return false;
27    }
28};