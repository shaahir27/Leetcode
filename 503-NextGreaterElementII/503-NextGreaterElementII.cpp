// Last updated: 10/20/2026, 11:08:12 PM
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
39output:   [-1,-1,-1,-1,5]
40expected: [-1, 5, 5, 5,5]
41
42Code: 
43
44stack<int> st;
45        vector<int> result;
46        int n = nums.size();
47
48        for(int i=n-1; i>=0; i--){
49            if(st.empty()){
50                if(i==n-1){
51                    bool found = false;
52                    for(int j=0; j<n-1; j++){
53                        if(nums[j] > nums[i]){
54                            result.insert(result.begin(), nums[j]);
55                            found = true;
56                            break;
57                        }
58                    }
59
60                    if(!found) result.insert(result.begin(), -1);
61                    st.push(nums[i]);
62                    continue;
63                }
64
65                result.insert(result.begin(), -1);
66                st.push(nums[i]);
67                continue;
68            }
69
70            while(!st.empty() && nums[i] > st.top()){
71                st.pop();
72            }
73
74            if(st.empty()){
75                result.insert(result.begin(), -1);
76            }
77            else{
78                result.insert(result.begin(), st.top());
79            }
80
81            st.push(nums[i]);
82        }
83
84        return result;
85    }
86
87*/