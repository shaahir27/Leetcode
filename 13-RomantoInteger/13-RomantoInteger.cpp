// Last updated: 8/30/2026, 11:21:56 PM
1class Solution {
2public:
3    int romanToInt(string s) {
4        int res = 0;
5
6        // Map of Roman numerals to their integer values
7        unordered_map<char, int> roman = {
8            {'I', 1}, {'V', 5}, {'X', 10},
9            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
10        };
11
12        // Iterate through the string, except the last character
13        for (int i = 0; i < s.size() - 1; i++) {
14            // Subtract if current numeral is less than the next
15            if (roman[s[i]] < roman[s[i + 1]]) {
16                res -= roman[s[i]];
17            } else {
18                // Otherwise, add the current value
19                res += roman[s[i]];
20            }
21        }
22
23        // Add the value of the last character
24        return res + roman[s.back()];
25    }
26};