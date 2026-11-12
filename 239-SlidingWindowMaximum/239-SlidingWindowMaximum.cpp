// Last updated: 11/12/2026, 10:41:27 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> dq; // Stores indices of useful elements // stores maximum's index
5        vector<int> result;
6        int start = 0;
7        
8        for (int i = 0; i < nums.size(); i++) {
9            // out of sliding window
10           if(!dq.empty() && dq.front() < start){
11                dq.pop_front();
12           }
13
14           while(!dq.empty() && nums[dq.back()] < nums[i]){
15                dq.pop_back();
16           }
17
18           dq.push_back(i);
19
20            if(i>=k-1){
21                result.push_back(nums[dq.front()]);
22                start++;
23            }
24        }
25        
26        return result;
27    }
28};
29
30/*
31
32class Solution {
33public:
34    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
35        int n = nums.size();
36        int maxi = INT_MIN;
37        int start = 0;
38
39        vector<int> result;
40
41        for(int i=0; i<n; i++){
42            maxi = max(maxi, nums[i]);
43
44            if((i + 1) >= k) {
45                result.push_back(maxi); 
46            
47                if(maxi == nums[start]) {
48                   maxi = INT_MIN;
49                    for(int j = start + 1; j <= i; j++) {
50                        maxi = max(maxi, nums[j]);
51                    }
52                }
53                start++;
54            }        
55        }
56
57        return result;
58    }
59};
60
61*/
62
63/*
64
65class Solution {
66public:
67    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
68        int n = nums.size();
69        int start = 0;
70        int end = k-1;
71
72        vector<int> result;
73
74        while(end < n){
75            int maxi = INT_MIN;
76            for(int i=start; i<=end; i++){
77                maxi = max(maxi, nums[i]); 
78            }
79
80            result.push_back(maxi);
81            start++;
82            end++;
83        }
84
85        return result;
86    }
87};
88
89*/