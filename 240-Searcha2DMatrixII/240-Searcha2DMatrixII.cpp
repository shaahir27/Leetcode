// Last updated: 9/4/2026, 10:32:52 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6
7        for(int i=0; i<n; i++){
8            int low = 0;
9            int high = m-1;
10
11            while(low <= high){
12                int mid = low + (high - low)/2;
13
14                if(matrix[i][mid] == target) return true;
15
16                if(matrix[i][mid] > target){
17                    high = mid - 1;
18                }
19                else{
20                    low = mid + 1;
21                }
22            }
23        }
24
25        return false;
26    }
27};