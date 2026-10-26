// Last updated: 10/26/2026, 11:23:39 PM
1class Solution {
2private:
3    // Finds the previous strictly smaller index for every element.
4    vector<int> findPreviousLess(vector<int>& arr) {
5        int n = arr.size();
6        vector<int> previousLess(n, -1);
7        stack<int> indices;
8 
9        // Scan from left to right for previous boundaries.
10        for (int i = 0; i < n; i++) {
11            // Remove values that are not strictly smaller.
12            while (!indices.empty() &&
13                   arr[indices.top()] >= arr[i]) {
14                indices.pop();
15            }
16 
17            // A remaining index is the previous smaller boundary.
18            if (!indices.empty()) {
19                previousLess[i] = indices.top();
20            }
21 
22            // Save the current index for later elements.
23            indices.push(i);
24        }
25 
26        return previousLess;
27    }
28 
29    // Finds the next smaller-or-equal index for every element.
30    vector<int> findNextLessOrEqual(vector<int>& arr) {
31        int n = arr.size();
32        vector<int> nextLessOrEqual(n, n);
33        stack<int> indices;
34 
35        // Scan from right to left for next boundaries.
36        for (int i = n - 1; i >= 0; i--) {
37            // Remove values that are strictly greater.
38            while (!indices.empty() &&
39                   arr[indices.top()] > arr[i]) {
40                indices.pop();
41            }
42 
43            // A remaining index is the next valid boundary.
44            if (!indices.empty()) {
45                nextLessOrEqual[i] = indices.top();
46            }
47 
48            // Save the current index for earlier elements.
49            indices.push(i);
50        }
51 
52        return nextLessOrEqual;
53    }
54 
55public:
56    // Returns the sum of all subarray minimums.
57    int sumSubarrayMins(vector<int>& arr) {
58        int n = arr.size();
59        long long mod = 1000000007;
60 
61        vector<int> previousLess = findPreviousLess(arr);
62        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
63 
64        long long answer = 0;
65 
66        // Calculate each element's contribution as the minimum.
67        for (int i = 0; i < n; i++) {
68            long long leftChoices = i - previousLess[i];
69            long long rightChoices = nextLessOrEqual[i] - i;
70 
71            // Count all subarrays where arr[i] owns the minimum.
72            long long contribution =
73                (arr[i] * leftChoices) % mod;
74            contribution =
75                (contribution * rightChoices) % mod;
76 
77            // Add the current contribution to the answer.
78            answer = (answer + contribution) % mod;
79        }
80 
81        return (int)answer;
82    }
83};
84
85/*
86Approach One
87
88class Solution {
89public:
90    int sumSubarrayMins(vector<int>& arr) {
91        int sum = 0;
92        int n = arr.size();
93
94        for(int i=0; i<n; i++){
95            for(int j=i; j<n; j++){
96                sum += *min_element(arr.begin() + i, arr.begin() + j + 1);
97            }
98        }
99
100        int mod = 1e9 + 7;
101        sum = sum % mod;
102        return sum;
103    }
104};
105
106*/