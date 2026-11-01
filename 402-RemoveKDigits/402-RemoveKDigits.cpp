// Last updated: 11/2/2026, 12:05:36 AM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        
5        string result = "";
6
7        for (char c : num) {
8
9            while (!result.empty() && k > 0 && result.back() > c) {
10                result.pop_back();
11                k--;
12            }
13
14            if (!result.empty() || c != '0') {
15                result.push_back(c);
16            }
17        }
18
19        while (!result.empty() && k > 0) {
20            result.pop_back();
21            k--;
22        }
23
24        return result.empty() ? "0" : result;
25    }
26};