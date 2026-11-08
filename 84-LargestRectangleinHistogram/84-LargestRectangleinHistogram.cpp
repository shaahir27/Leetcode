// Last updated: 11/8/2026, 10:17:53 PM
1class Solution {
2private:
3    vector<int> previousSmaller(vector<int>& heights){
4        int n = heights.size();
5        stack<int> st;
6        vector<int> previous(n, -1);
7
8        for(int i=0; i<n; i++){
9            while(!st.empty() && heights[st.top()] >= heights[i]){
10                st.pop();
11            }
12
13            if(!st.empty()) previous[i] = st.top();
14            st.push(i);
15        }
16
17        return previous;
18    }
19    vector<int> nextSmaller(vector<int>& heights){
20        int n = heights.size();
21        stack<int> st;
22        vector<int> next(n, n);
23
24        for(int i=n-1; i>=0; i--){
25            while(!st.empty() && heights[st.top()] > heights[i]){
26                st.pop();
27            }
28
29            if(!st.empty()) next[i] = st.top();
30            st.push(i);
31        }
32
33        return next;
34    }
35public:
36    int largestRectangleArea(vector<int>& heights) {
37        int n = heights.size();
38        if(n==1) return heights[0];
39
40        vector<int> pse = previousSmaller(heights);
41        vector<int> nse = nextSmaller(heights);
42        int maxi = 0;
43
44        for(int i=0; i<n; i++){
45            int area = heights[i] * (nse[i] - pse[i] - 1);
46            maxi = max(maxi, area);
47        }
48
49        return maxi;
50    }
51};