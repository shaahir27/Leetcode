// Last updated: 8/31/2026, 10:54:14 PM
1class Solution {
2public:
3    int myAtoi(string s) {
4        int result = 0;
5        int sign = 1;
6        bool started = false;
7
8        for(int i=0; i<s.length(); i++){
9            if(s[i] == ' '){
10                if(started) break;
11                continue;
12            }
13            else if(s[i] == '+'){
14                if(started) break;
15                started = true;
16                continue;
17            }
18            else if(s[i] == '-'){
19                if(started) break;
20                sign = -1;
21                started = true;
22            }
23            else if(isdigit(s[i])){
24                int digit = s[i] - '0';
25
26                if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)){
27                    return sign == 1 ? INT_MAX : INT_MIN;
28                }
29
30                result = result * 10 + digit;
31                started = true;
32            }
33            else{
34                break;
35            }
36        }
37
38        return result * sign;
39    }
40};
41
42
43/*
44
45class Solution {
46public:
47    int myAtoi(string s) {
48        int i = 0;
49        int n = s.size();
50        int sign = 1;
51        long long result = 0;
52
53        // 1. Skip leading spaces
54        while (i < n && s[i] == ' ')
55            i++;
56
57        // 2. Check sign
58        if (i < n && (s[i] == '+' || s[i] == '-')) {
59            if (s[i] == '-')
60                sign = -1;
61            i++;
62        }
63
64        // 3. Read digits
65        while (i < n && isdigit(s[i])) {
66            int digit = s[i] - '0';
67
68            // Check overflow before multiplying
69            if (result > INT_MAX / 10 ||
70                (result == INT_MAX / 10 && digit > 7)) {
71                return sign == 1 ? INT_MAX : INT_MIN;
72            }
73
74            result = result * 10 + digit;
75            i++;
76        }
77
78        return result * sign;
79    }
80};
81
82
83*/