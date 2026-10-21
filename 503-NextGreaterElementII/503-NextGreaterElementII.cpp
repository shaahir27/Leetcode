// Last updated: 10/21/2026, 10:47:25 PM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> result(n, -1);
6        stack<int> st;
7
8        // Loop twice to handle the circular array constraint
9        for (int i = 2 * n - 1; i >= 0; i--) {
10            int num = nums[i % n];
11
12            while (!st.empty() && st.top() <= num) {
13                st.pop();
14            }
15
16            // Record result on the first pass (for original indices 0 to n-1)
17            if (i < n) {
18                if(st.empty()){
19                    result[i] = -1;
20                }
21                else{
22                    result[i] = st.top();
23                }
24            }
25
26            st.push(num);
27        }
28
29        return result;
30    }
31};
32
33/*
34My Aprroach
35
36Reason for failing: 
37nums = [5,4,3,2,1]
38
39output:   [-1,-1,-1,-1, 5]
40expected: [-1, 5, 5, 5, 5]
41
42Code: 
43
44class Solution {
45public:
46    vector<int> nextGreaterElements(vector<int>& nums) {
47        stack<int> st;
48        vector<int> result;
49        int n = nums.size();
50
51        for(int i=n-1; i>=0; i--){
52            if(st.empty()){
53                if(i==n-1){
54                    bool found = false;
55                    for(int j=0; j<n-1; j++){
56                        if(nums[j] > nums[i]){
57                            result.insert(result.begin(), nums[j]);
58                            found = true;
59                            break;
60                        }
61                    }
62
63                    if(!found) result.insert(result.begin(), -1);
64                    st.push(nums[i]);
65                    continue;
66                }
67
68                result.insert(result.begin(), -1);
69                st.push(nums[i]);
70                continue;
71            }
72
73            while(!st.empty() && nums[i] > st.top()){
74                st.pop();
75            }
76
77            if(st.empty()){
78                result.insert(result.begin(), -1);
79            }
80            else{
81                result.insert(result.begin(), st.top());
82            }
83
84            st.push(nums[i]);
85        }
86
87        return result;
88    }
89*/