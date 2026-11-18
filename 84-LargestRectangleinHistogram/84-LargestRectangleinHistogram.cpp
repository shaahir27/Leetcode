// Last updated: 11/18/2026, 10:03:31 PM
1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<int> st;
5        int maxArea = INT_MIN;
6        int n = heights.size();
7
8        for(int i=0; i<n; i++){
9            while(!st.empty() && heights[st.top()] > heights[i]){
10                int element = st.top();
11                st.pop();
12
13                int nse = i;
14                int pse = st.empty() ? -1 : st.top();
15
16                int area = heights[element] * (nse - pse - 1);
17                maxArea = max(maxArea, area);
18            }
19
20            st.push(i);
21        }
22
23        while(!st.empty()){
24            int element = st.top();
25            st.pop();
26
27            int nse = n;
28            int pse = st.empty() ? -1 : st.top();
29
30            int area = heights[element] * (nse - pse - 1);
31            maxArea = max(maxArea, area);
32        }
33
34        return maxArea;
35    }
36};
37
38/*
39Approach 1
40
41
42class Solution {
43private:
44    vector<int> previousSmaller(vector<int>& heights){
45        int n = heights.size();
46        stack<int> st;
47        vector<int> previous(n, -1);
48
49        for(int i=0; i<n; i++){
50            while(!st.empty() && heights[st.top()] >= heights[i]){
51                st.pop();
52            }
53
54            if(!st.empty()) previous[i] = st.top();
55            st.push(i);
56        }
57
58        return previous;
59    }
60    vector<int> nextSmaller(vector<int>& heights){
61        int n = heights.size();
62        stack<int> st;
63        vector<int> next(n, n);
64
65        for(int i=n-1; i>=0; i--){
66            while(!st.empty() && heights[st.top()] > heights[i]){
67                st.pop();
68            }
69
70            if(!st.empty()) next[i] = st.top();
71            st.push(i);
72        }
73
74        return next;
75    }
76
77public:
78    int largestRectangleArea(vector<int>& heights) {
79        int n = heights.size();
80        if(n==1) return heights[0];
81
82        vector<int> pse = previousSmaller(heights);
83        vector<int> nse = nextSmaller(heights);
84        int maxi = 0;
85
86        for(int i=0; i<n; i++){
87            int area = heights[i] * (nse[i] - pse[i] - 1); /// here heights[i] = height, (nse[i] - pse[i] - 1) = width
88            maxi = max(maxi, area);
89        }
90
91        return maxi;
92    }
93};
94*/