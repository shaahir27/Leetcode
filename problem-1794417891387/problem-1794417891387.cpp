// Last updated: 11/11/2026, 10:54:51 PM
1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        vector<vector<int>> matrix(n, vector<int>(n, 0));
5        int left = 0, right = n-1;
6        int top = 0, bottom = n-1;
7
8        int val = 0;
9
10        while(top<=bottom && left<=right){
11            // left -> right
12            for(int i=left; i<=right; i++){
13                matrix[top][i] = ++val;
14            }
15            top++;
16
17            //top to bottom
18            for(int i=top; i<=bottom; i++){
19                matrix[i][right] = ++val;
20            }
21            right--;
22
23            // right to left
24            if(top<=bottom){
25                for(int i=right; i>=left; i--){
26                    matrix[bottom][i] = ++val;
27                }
28            }
29            bottom--;
30
31            //bottom to top
32            if(left<=right){
33                for(int i=bottom; i>=top; i--){
34                    matrix[i][left] = ++val;
35                }
36            }
37            left++;
38        }
39
40        return matrix;
41    }
42};