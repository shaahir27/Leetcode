// Last updated: 9/17/2026, 9:11:24 PM
1class Solution {
2public:
3    string longestPalindrome(string s) {
4
5        int n = s.length();
6
7        int bestStart = 0;
8        int bestLength = 1;
9
10        for (int i = 0; i < n; i++) {
11
12            for (int j = i; j < n; j++) {
13
14                int left = i;
15                int right = j;
16
17                bool isPalindrome = true;
18
19                while (left < right) {
20
21                    if (s[left] != s[right]) {
22                        isPalindrome = false;
23                        break;
24                    }
25
26                    left++;
27                    right--;
28                }
29
30                if (isPalindrome && (j - i + 1) > bestLength) {
31                    bestStart = i;
32                    bestLength = j - i + 1;
33                }
34            }
35        }
36
37        return s.substr(bestStart, bestLength);
38    }
39};