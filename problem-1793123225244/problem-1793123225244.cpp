// Last updated: 10/27/2026, 11:17:05 PM
1class Solution {
2private:
3    // Finds the previous strictly smaller index for every element.
4    vector<int> findPreviousLess(vector<int>& arr) {
5        int n = arr.size();
6        vector<int> previousLess(n, -1);
7        stack<int> indices;
8
9        for (int i = 0; i < n; i++) {
10            
11            while (!indices.empty() &&
12                   arr[indices.top()] >= arr[i]) {
13                indices.pop();
14            }
15
16            if (!indices.empty()) {
17                previousLess[i] = indices.top();
18            }
19
20            indices.push(i);
21        }
22 
23        return previousLess;
24    }
25
26    vector<int> findNextLessOrEqual(vector<int>& arr) {
27        int n = arr.size();
28        vector<int> nextLessOrEqual(n, n);
29        stack<int> indices;
30
31        for (int i = n - 1; i >= 0; i--) {
32
33            while (!indices.empty() &&
34                   arr[indices.top()] > arr[i]) {
35                indices.pop();
36            }
37
38            if (!indices.empty()) {
39                nextLessOrEqual[i] = indices.top();
40            }
41
42            indices.push(i);
43        }
44 
45        return nextLessOrEqual;
46    }
47 
48public:
49    int sumSubarrayMins(vector<int>& arr) {
50        int n = arr.size();
51        long long mod = 1000000007;
52 
53        vector<int> previousLess = findPreviousLess(arr);
54        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
55 
56        long long answer = 0;
57 
58        for (int i = 0; i < n; i++) {
59            long long left = i - previousLess[i];
60            long long right = nextLessOrEqual[i] - i;
61
62            answer += (left * right * 1LL * arr[i]);
63        }
64
65        answer %= mod;
66 
67        return (int)answer;
68    }
69};
70
71/*
72Approach One
73
74class Solution {
75public:
76    int sumSubarrayMins(vector<int>& arr) {
77        int sum = 0;
78        int n = arr.size();
79
80        for(int i=0; i<n; i++){
81            for(int j=i; j<n; j++){
82                sum += *min_element(arr.begin() + i, arr.begin() + j + 1);
83            }
84        }
85
86        int mod = 1e9 + 7;
87        sum = sum % mod;
88        return sum;
89    }
90};
91
92*/