// Last updated: 9/17/2026, 10:06:58 PM
1class Solution {
2public:
3    string longestPalindrome(string s){
4        int n = s.length();
5        string result = "";
6
7        for(int i=0; i<n; i++){
8            // Odd Case
9            int start = i, end = i;
10            while(start>=0 && end<n && s[start] == s[end]){
11                start--;
12                end++;
13            }
14
15            string temp = s.substr(start+1, end - start - 1);
16            if(temp.length() > result.length()) result = temp;
17
18            //Even Case
19            start = i;
20            end = i+1;
21            
22            while(start>=0 && end<n && s[start] == s[end]){
23                start--;
24                end++;
25            }
26
27            temp = s.substr(start+1, end - start - 1);
28            if(temp.length() > result.length()) result = temp;
29        }
30
31        return result;
32    }
33};
34
35/*
36
37My rute force approach
38
39string longestPalindrome(string s) {
40
41    int n = s.length();
42
43    int bestStart = 0;
44    int bestLength = 1;
45
46    for (int i = 0; i < n; i++) {
47
48        for (int j = i; j < n; j++) {
49
50            int left = i;
51            int right = j;
52
53            bool isPalindrome = true;
54
55            while (left < right) {
56
57                if (s[left] != s[right]) {
58                    isPalindrome = false;
59                    break;
60                }
61
62                left++;
63                right--;
64            }
65
66            if (isPalindrome && (j - i + 1) > bestLength) {
67                bestStart = i;
68                bestLength = j - i + 1;
69            }
70        }
71    }
72
73    return s.substr(bestStart, bestLength);
74}
75
76*/