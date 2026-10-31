// Last updated: 10/31/2026, 11:39:09 PM
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
35    /*
36    vector<long long> findSubarrayMinimum(vector<int>& arr){
37        int n = arr.size();
38        vector<long long> subarrayMinimum(n);
39        vector<int> previousLess = findPreviousLess(arr);
40        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
41
42        for(int i=0; i<n; i++){
43            int left = i - previousLess[i];
44            int right = nextLessOrEqual[i] - i;
45
46            subarrayMinimum[i] = 1LL * left * right * arr[i];
47        }
48
49        return subarrayMinimum;
50    }
51    */
52    vector<int> findPreviousGreater(vector<int>& arr){
53        int n = arr.size();
54        stack<int> indices;
55        vector<int> previousGreater(n, -1);
56
57        for(int i=0; i<n; i++){
58            while(!indices.empty() && arr[indices.top()] <= arr[i]){
59                indices.pop();
60            }
61
62            if(!indices.empty()) previousGreater[i] = indices.top();
63            indices.push(i);
64        }
65
66        return previousGreater;
67    }
68    vector<int> findNextGreaterOrEqual(vector<int>& arr){
69        int n = arr.size();
70        stack<int> indices;
71        vector<int> nextGreater(n, n);
72
73        for(int i=n-1; i>=0; i--){
74            while(!indices.empty() && arr[indices.top()] < arr[i]){
75                indices.pop();
76            }
77
78            if(!indices.empty()) nextGreater[i] = indices.top();
79            indices.push(i);
80        }
81
82        return nextGreater;
83    }
84    /*
85    vector<long long> findSubarrayMaximum(vector<int>& arr){
86        int n = arr.size();
87        vector<long long> subarrayMaximum(n);
88        vector<int> previousGreater = findPreviousGreater(arr);
89        vector<int> nextGreaterOrEqual = findNextGreaterOrEqual(arr);
90
91        for(int i=0; i<n; i++){
92            int left = i - previousGreater[i];
93            int right = nextGreaterOrEqual[i] - i;
94
95            subarrayMaximum[i] = 1LL * left * right * arr[i];
96        }
97
98        return subarrayMaximum;
99    }
100    */
101public:
102    long long subArrayRanges(vector<int>& nums) {
103
104        int n = nums.size();
105        long long sum = 0;
106
107        vector<int> previousLess = findPreviousLess(nums);
108        vector<int> nextLessOrEqual = findNextLessOrEqual(nums);
109        vector<int> previousGreater = findPreviousGreater(nums);
110        vector<int> nextGreaterOrEqual = findNextGreaterOrEqual(nums);
111
112        /*
113        vector<long long>subarrayMinimum = findSubarrayMinimum(nums);
114        vector<long long>subarrayMaximum = findSubarrayMaximum(nums);
115        */
116
117        for(int i=0; i<n; i++){
118            long long minimum = 1LL * (i - previousLess[i]) * (nextLessOrEqual[i] - i) * nums[i];
119            long long maximum = 1LL * (i - previousGreater[i]) * (nextGreaterOrEqual[i] - i) * nums[i];
120
121            sum += maximum - minimum;
122        }  
123
124        return sum;
125    }
126};
127
128
129/*
130Brute force
131
132class Solution {
133public:
134    long long subArrayRanges(vector<int>& nums) {
135        long long sum = 0;
136
137        for(int i=0; i<nums.size(); i++){
138            int highest = nums[i];
139            int lowest = nums[i];
140            for(int j=i; j<nums.size(); j++){
141                if(highest < nums[j]) highest = nums[j];
142                if(lowest > nums[j]) lowest = nums[j];
143
144                sum += (highest - lowest);
145            }
146        }
147
148        return sum;
149    }
150};
151
152*/