// Last updated: 11/24/2026, 4:41:33 PM
1class Solution {
2private:
3    int largestRectangleArea(vector<int>& heights){
4        int maxArea = 0;
5        int n = heights.size();
6        stack<int> st;
7
8        for(int i=0; i<n; i++){
9            
10            while(!st.empty() && heights[st.top()] > heights[i]){
11                int element = heights[st.top()];
12                st.pop();
13                int nse = i;
14                int pse = st.empty() ? -1 : st.top();
15
16                int area = element * (nse - pse - 1);
17                maxArea = max(maxArea, area);
18            }
19            
20            st.push(i);
21        }
22
23        while(!st.empty()){
24            int element = heights[st.top()];
25            st.pop();
26            int pse = st.empty() ? -1 : st.top();
27
28            int area = element * (n - pse - 1);
29            maxArea = max(maxArea, area);
30
31        }
32    
33        return maxArea;
34    }
35public:
36    int maximalRectangle(vector<vector<char>>& matrix) {
37        int n = matrix.size();
38        int m = matrix[0].size();
39
40        int maxArea = 0;
41
42        vector<int> heights(m, 0);
43
44        for(int i=0; i<n; i++){
45            for(int j=0; j<m; j++){
46                if(matrix[i][j] == '1') heights[j]++;
47                else heights[j] = 0;
48            }
49
50            maxArea = max(maxArea, largestRectangleArea(heights));
51        }
52
53        return maxArea;
54    }
55};