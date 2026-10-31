// Last updated: 10/31/2026, 11:20:20 PM
1class Solution {
2private:
3    vector<int> findPreviousLess(vector<int>& arr){
4        int n = arr.size();
5        stack<int> indices;
6        vector<int> previousLess(n, -1);
7
8        for(int i=0; i<n; i++){
9            while(!indices.empty() && arr[indices.top()] >= arr[i]){
10                indices.pop();
11            }
12
13            if(!indices.empty()) previousLess[i] = indices.top();
14            indices.push(i);
15        }
16
17        return previousLess;
18    }
19    vector<int> findNextLessOrEqual(vector<int>& arr){
20        int n = arr.size();
21        stack<int> indices;
22        vector<int> nextLess(n, n);
23
24        for(int i=n-1; i>=0; i--){
25            while(!indices.empty() && arr[indices.top()] > arr[i]){
26                indices.pop();
27            }
28
29            if(!indices.empty()) nextLess[i] = indices.top();
30            indices.push(i);
31        }
32
33        return nextLess;
34    }
35    vector<long long> findSubarrayMinimum(vector<int>& arr){
36        int n = arr.size();
37        vector<long long> subarrayMinimum(n);
38        vector<int> previousLess = findPreviousLess(arr);
39        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
40
41        for(int i=0; i<n; i++){
42            int left = i - previousLess[i];
43            int right = nextLessOrEqual[i] - i;
44
45            subarrayMinimum[i] = 1LL * left * right * arr[i];
46        }
47
48        return subarrayMinimum;
49    }
50    vector<int> findPreviousGreater(vector<int>& arr){
51        int n = arr.size();
52        stack<int> indices;
53        vector<int> previousGreater(n, -1);
54
55        for(int i=0; i<n; i++){
56            while(!indices.empty() && arr[indices.top()] <= arr[i]){
57                indices.pop();
58            }
59
60            if(!indices.empty()) previousGreater[i] = indices.top();
61            indices.push(i);
62        }
63
64        return previousGreater;
65    }
66    vector<int> findNextGreaterOrEqual(vector<int>& arr){
67        int n = arr.size();
68        stack<int> indices;
69        vector<int> nextGreater(n, n);
70
71        for(int i=n-1; i>=0; i--){
72            while(!indices.empty() && arr[indices.top()] < arr[i]){
73                indices.pop();
74            }
75
76            if(!indices.empty()) nextGreater[i] = indices.top();
77            indices.push(i);
78        }
79
80        return nextGreater;
81    }
82    vector<long long> findSubarrayMaximum(vector<int>& arr){
83        int n = arr.size();
84        vector<long long> subarrayMaximum(n);
85        vector<int> previousGreater = findPreviousGreater(arr);
86        vector<int> nextGreaterOrEqual = findNextGreaterOrEqual(arr);
87
88        for(int i=0; i<n; i++){
89            int left = i - previousGreater[i];
90            int right = nextGreaterOrEqual[i] - i;
91
92            subarrayMaximum[i] = 1LL * left * right * arr[i];
93        }
94
95        return subarrayMaximum;
96    }
97public:
98    long long subArrayRanges(vector<int>& nums) {
99        int n = nums.size();
100        long long sum = 0;
101        vector<long long>subarrayMinimum = findSubarrayMinimum(nums);
102        vector<long long>subarrayMaximum = findSubarrayMaximum(nums);
103
104        for(int i=0; i<n; i++){
105            sum += subarrayMaximum[i] - subarrayMinimum[i];
106        }  
107
108        return sum;
109    }
110};
111
112
113/*
114Brute force
115
116class Solution {
117public:
118    long long subArrayRanges(vector<int>& nums) {
119        long long sum = 0;
120
121        for(int i=0; i<nums.size(); i++){
122            int highest = nums[i];
123            int lowest = nums[i];
124            for(int j=i; j<nums.size(); j++){
125                if(highest < nums[j]) highest = nums[j];
126                if(lowest > nums[j]) lowest = nums[j];
127
128                sum += (highest - lowest);
129            }
130        }
131
132        return sum;
133    }
134};
135
136*/